/* ENC28J60 Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
// #include <iostream>
// extern "C"
//{
#include <stdio.h>
// #include <string.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_netif.h"
#include "esp_eth.h"
#include "esp_event.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "esp_eth_enc28j60.h"
#include "driver/spi_master.h"

// #include <stdio.h>
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "esp_spiffs.h"

#include "freertos/event_groups.h"
#include "esp_system.h"
// #include "esp_log.h"
#include <netdb.h>
#include "nvs_flash.h"

#include <esp_http_server.h>

#include <stdio.h>
#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include "esp_err.h"
#include "esp_log.h"
#include "esp_spiffs.h"
#include "esp_spi_flash.h"
#include <esp_http_server.h>
// #include "nvs_flash.h"

#include "driver/uart.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

#include <sys/dirent.h>

#include <sstream>

//#include "connect_wifi.h"

// #include <esp_log.h>
// #include <esp_http_server.h>
// #include <esp_vfs.h>
// #include <sys/unistd.h>
// #include <sys/stat.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <esp_wifi.h>
#include <esp_netif.h>
// #include <http_app.h>
#include <freertos/FreeRTOS.h>
#include <esp_http_server.h>
#include <freertos/task.h>
#include <freertos/event_groups.h>
#include <esp_ota_ops.h>
#include <esp_system.h>
#include <lwip/ip4_addr.h>
#include <esp_log.h>
#include <nvs_flash.h>
#include <sys/param.h>

#include <driver/gpio.h>
// #include <cJSON.h>

#include "global.h"
#include "My_server.h"
#include "Traffic_lights.h"

// #include "/home/ssv/libraries_cpp/l_json/json/include/nlohmann/json.hpp"

// using namespace std;

#define EXAMPLE_STATIC_IP_ADDR "192.168.2.17"
#define EXAMPLE_STATIC_NETMASK_ADDR "255.255.255.0"
#define EXAMPLE_STATIC_GW_ADDR "192.168.2.1"
#ifdef CONFIG_EXAMPLE_STATIC_DNS_AUTO
#define EXAMPLE_MAIN_DNS_SERVER EXAMPLE_STATIC_GW_ADDR
#define EXAMPLE_BACKUP_DNS_SERVER "8.8.8.8"
#else
#define EXAMPLE_MAIN_DNS_SERVER "192.168.2.1" // CONFIG_EXAMPLE_STATIC_DNS_SERVER_MAIN
#define EXAMPLE_BACKUP_DNS_SERVER "8.8.8.8"   // CONFIG_EXAMPLE_STATIC_DNS_SERVER_BACKUP
#endif

int led_state = 0;

esp_err_t server_index(httpd_req_t *req)
{
  // return send_web_page(req);
  int response = httpd_resp_send(req, web().c_str(), HTTPD_RESP_USE_STRLEN);
  return response;
}
esp_err_t YF_ON(httpd_req_t *req)
{
  yellow_flashing_state = "on";
  os_state = "off";
  manual_mode_state = "off";
  main_mode_state = "off";
  // return send_web_page(req);
  int response = httpd_resp_send(req, web().c_str(), HTTPD_RESP_USE_STRLEN);
  return response;
}
esp_err_t YF_OFF(httpd_req_t *req)
{
  yellow_flashing_state = "off";
  // return send_web_page(req);
  int response = httpd_resp_send(req, web().c_str(), HTTPD_RESP_USE_STRLEN);
  return response;
}

esp_err_t MM_ON(httpd_req_t *req)
{
  main_mode_state = "on";
  yellow_flashing_state = "off";
  os_state = "off";
  manual_mode_state = "off";
  // return send_web_page(req);
  int response = httpd_resp_send(req, web().c_str(), HTTPD_RESP_USE_STRLEN);
  return response;
}
esp_err_t MM_OFF(httpd_req_t *req)
{
  main_mode_state = "off";
  // return send_web_page(req);
  int response = httpd_resp_send(req, web().c_str(), HTTPD_RESP_USE_STRLEN);
  return response;
}

esp_err_t OS_ON(httpd_req_t *req)
{
  os_state = "on";
  manual_mode_state = "off";
  yellow_flashing_state = "off";
  main_mode_state = "off";
  // return send_web_page(req);
  int response = httpd_resp_send(req, web().c_str(), HTTPD_RESP_USE_STRLEN);
  return response;
}
esp_err_t OS_OFF(httpd_req_t *req)
{
  os_state = "off";
  // return send_web_page(req);
  int response = httpd_resp_send(req, web().c_str(), HTTPD_RESP_USE_STRLEN);
  return response;
}
esp_err_t Manual_ON(httpd_req_t *req)
{
  os_state = "off";
  manual_mode_state = "on";
  yellow_flashing_state = "off";
  main_mode_state = "off";
  // return send_web_page(req);
  //  faza = optionValue.toInt() + 1;
  faza = int(req->content_len);
  // std::cout << faza << std::endl;
  int response = httpd_resp_send(req, web().c_str(), HTTPD_RESP_USE_STRLEN);
  return response;
}
esp_err_t Manual_OFF(httpd_req_t *req)
{
  manual_mode_state = "off";
  // return send_web_page(req);
  int response = httpd_resp_send(req, web().c_str(), HTTPD_RESP_USE_STRLEN);
  return response;
}

esp_err_t Manual(httpd_req_t *req)
{
  char content[100]; // Предположим, что размер данных формы не превышает 100 байт
  int received = httpd_req_recv(req, content, sizeof(content));
  if (received <= 0)
  { // Проверка на ошибку или закрытие соединения
    if (received == HTTPD_SOCK_ERR_TIMEOUT)
    {
      /* В случае тайм-аута, вы можете повторно отправить запрос на чтение данных */
      httpd_resp_send_408(req);
    }
    return ESP_FAIL;
  }

  /* Парсинг полученных данных */
  char *fazaValue = strstr(content, "faza=");
  if (fazaValue)
  {
    fazaValue += 5; // Сдвиг на размер ключа, чтобы получить значение
    faza = atoi(fazaValue) + 1;

    /* Здесь вы можете использовать переменную faza по вашему усмотрению */

    /* Отправка ответа */
    const char *resp = web().c_str(); // Предположим, функция web() возвращает HTML страницу в виде строки
    httpd_resp_send(req, web().c_str(), HTTPD_RESP_USE_STRLEN);
    return ESP_OK;
  }

  /* Если данные не содержат ключ 'faza', отправляем 400 Bad Request */
  // httpd_resp_send_400(req);
  return ESP_FAIL;
};

esp_err_t Upload(httpd_req_t *req)
{
  char buf[1024];
  int remaining = req->content_len;
  FILE *fd = fopen("/spiffs/data.json", "w");
  if (!fd)
  {
    ESP_LOGE("Upload", "Failed to open file for writing");
    return ESP_FAIL; // Возврат ошибки, если файл не может быть открыт
  }

  while (remaining > 0)
  {
    int recv_len = httpd_req_recv(req, buf, MIN(remaining, sizeof(buf)));
    if (recv_len <= 0)
    {
      fclose(fd);
      if (recv_len == HTTPD_SOCK_ERR_TIMEOUT)
      {
        httpd_resp_send_408(req);
      }
      return ESP_FAIL;
    }

    int write_len = fwrite(buf, 1, recv_len, fd);
    if (write_len != recv_len)
    {
      ESP_LOGE("Upload", "File write failed");
      fclose(fd);
      return ESP_FAIL;
    }

    remaining -= recv_len;
  }

  fclose(fd);
  ESP_LOGI("Upload", "File upload succeeded");

  httpd_resp_set_status(req, "303 See Other");
  // httpd_resp_set_hdr(req, "Location", "/success.html"); // Перенаправление на страницу success.html
  httpd_resp_set_hdr(req, "Location", "/");
  httpd_resp_send_chunk(req, NULL, 0); // Завершение передачи данных
  // httpd_resp_sendstr(req, web().c_str());
  json_desearelization();

  return ESP_OK;
}

esp_err_t Download(httpd_req_t *req)
{
  std::cout << "download" << std::endl;
  FILE *f = fopen("/spiffs/data.json", "r");
  if (f == NULL)
  {
    ESP_LOGE(TAG, "Failed to open file for reading");
    httpd_resp_send_404(req);
    return ESP_FAIL;
  }

  // Определение размера файла
  fseek(f, 0, SEEK_END);
  size_t file_size = ftell(f);
  rewind(f);

  // Выделяем буфер для хранения содержимого файла
  char *buffer = (char *)malloc(file_size + 1);
  if (buffer == NULL)
  {
    fclose(f);
    // Обработка ошибки
  }

  // Чтение содержимого файла в буфер
  size_t read_size = fread(buffer, 1, file_size, f);
  fclose(f);
  if (read_size < file_size)
  {
    free(buffer);
    // Обработка ошибки
  }

  // char buf[16384];
  // size_t read_bytes;
  // do
  // {
  //   read_bytes = fread(buf, 1, sizeof(buf), f);
  //   if (read_bytes > 0)
  //   {
  //     if (httpd_resp_send_chunk(req, buf, read_bytes) != ESP_OK)
  //     {
  //       fclose(f);
  //       ESP_LOGE(TAG, "File sending failed!");
  //       return ESP_FAIL;
  //     }
  //   }
  // } while (read_bytes > 0);
  // httpd_resp_set_type(req, "application/octet-stream");
  httpd_resp_set_type(req, "application/octet-stream");
  //  http_body_is_final(f);
  httpd_resp_set_hdr(req, "Content-Disposition", "attachment; filename=data.json");
  // httpd_resp_send(req, "/spiffs/data.json",16384);
  std::ifstream file("/spiffs/data.json");
  // const char *c_filename = file.c_str();
  httpd_resp_send(req, buffer, file_size);
  // httpd_resp_send_chunk(req, NULL, 0);
  // fclose(f);
  free(buffer);
  // httpd_resp_send_chunk(req, NULL, 0);
  return ESP_OK;
}

httpd_uri_t uri_get = {
    .uri = "/",
    .method = HTTP_GET,
    .handler = server_index,
    .user_ctx = NULL};

httpd_uri_t yellow_flashing_on = {
    .uri = "/yellow_flashing/on",
    .method = HTTP_GET,
    .handler = YF_ON,
    .user_ctx = NULL};

httpd_uri_t yellow_flashing_off = {
    .uri = "/yellow_flashing/off",
    .method = HTTP_GET,
    .handler = YF_OFF,
    .user_ctx = NULL};

httpd_uri_t main_mode_on = {
    .uri = "/main_mode/on",
    .method = HTTP_GET,
    .handler = MM_ON,
    .user_ctx = NULL};

httpd_uri_t main_mode_off = {
    .uri = "/main_mode/off",
    .method = HTTP_GET,
    .handler = MM_OFF,
    .user_ctx = NULL};

httpd_uri_t os_on = {
    .uri = "/os/on",
    .method = HTTP_GET,
    .handler = OS_ON,
    .user_ctx = NULL};

httpd_uri_t os_off = {
    .uri = "/os/off",
    .method = HTTP_GET,
    .handler = OS_OFF,
    .user_ctx = NULL};

httpd_uri_t upload = {
    //.uri       = "/download",
    .uri = "/upload",
    .method = HTTP_POST,
    .handler = Upload,
    .user_ctx = NULL};

httpd_uri_t download = {
    .uri = "/download",
    //.uri = "/upload",
    .method = HTTP_POST,
    .handler = Download,
    .user_ctx = NULL};

httpd_uri_t manual_on = {
    .uri = "/manual_mode/on",
    .method = HTTP_GET,
    .handler = Manual_ON,
    .user_ctx = NULL};

httpd_uri_t manual_off = {
    .uri = "/manual_mode/off",
    .method = HTTP_GET,
    .handler = Manual_OFF,
    .user_ctx = NULL};

httpd_uri_t manual = {
    .uri = "/manual",
    .method = HTTP_POST,
    .handler = Manual,
    .user_ctx = NULL};

httpd_handle_t setup_server(void)
{
  httpd_config_t config = HTTPD_DEFAULT_CONFIG();
  //  httpd_config_t config = HTTPD_DEFAULT_CONFIG();
  config.max_uri_handlers = 20;
  config.uri_match_fn = httpd_uri_match_wildcard;

  httpd_handle_t server = NULL;

  if (httpd_start(&server, &config) == ESP_OK)
  {
    httpd_register_uri_handler(server, &uri_get);
    httpd_register_uri_handler(server, &yellow_flashing_on);
    httpd_register_uri_handler(server, &yellow_flashing_off);
    httpd_register_uri_handler(server, &main_mode_on);
    httpd_register_uri_handler(server, &main_mode_off);
    httpd_register_uri_handler(server, &os_on);
    httpd_register_uri_handler(server, &os_off);
    httpd_register_uri_handler(server, &upload);
    httpd_register_uri_handler(server, &download);
    httpd_register_uri_handler(server, &manual_on);
    httpd_register_uri_handler(server, &manual_off);
    httpd_register_uri_handler(server, &manual);
  }

  return server;
}

int reqCount = 0; // number of requests received

static esp_err_t example_set_dns_server(esp_netif_t *netif, uint32_t addr, esp_netif_dns_type_t type)
{
  if (addr && (addr != IPADDR_NONE))
  {
    esp_netif_dns_info_t dns;
    dns.ip.u_addr.ip4.addr = addr;
    dns.ip.type = IPADDR_TYPE_V4;
    ESP_ERROR_CHECK(esp_netif_set_dns_info(netif, type, &dns));
  }
  return ESP_OK;
}

static void example_set_static_ip(esp_netif_t *netif)
{
  if (esp_netif_dhcpc_stop(netif) != ESP_OK)
  {
    ESP_LOGE(TAG, "Failed to stop dhcp client");
    return;
  }
  esp_netif_ip_info_t ip;
  memset(&ip, 0, sizeof(esp_netif_ip_info_t));
  ip.ip.addr = ipaddr_addr(EXAMPLE_STATIC_IP_ADDR);
  ip.netmask.addr = ipaddr_addr(EXAMPLE_STATIC_NETMASK_ADDR);
  ip.gw.addr = ipaddr_addr(EXAMPLE_STATIC_GW_ADDR);
  if (esp_netif_set_ip_info(netif, &ip) != ESP_OK)
  {
    ESP_LOGE(TAG, "Failed to set ip info");
    return;
  }
  ESP_LOGD(TAG, "Success to set static ip: %s, netmask: %s, gw: %s", EXAMPLE_STATIC_IP_ADDR, EXAMPLE_STATIC_NETMASK_ADDR, EXAMPLE_STATIC_GW_ADDR);
  ESP_ERROR_CHECK(example_set_dns_server(netif, ipaddr_addr(EXAMPLE_MAIN_DNS_SERVER), ESP_NETIF_DNS_MAIN));
  ESP_ERROR_CHECK(example_set_dns_server(netif, ipaddr_addr(EXAMPLE_BACKUP_DNS_SERVER), ESP_NETIF_DNS_BACKUP));
}

/** Event handler for Ethernet events */
static void eth_event_handler(void *arg, esp_event_base_t event_base,
                              int32_t event_id, void *event_data)
{
  uint8_t mac_addr[6] = {0};
  /* we can get the ethernet driver handle from event data */
  esp_eth_handle_t eth_handle = *(esp_eth_handle_t *)event_data;

  switch (event_id)
  {
  case ETHERNET_EVENT_CONNECTED:
    esp_eth_ioctl(eth_handle, ETH_CMD_G_MAC_ADDR, mac_addr);
    ESP_LOGI(TAG, "Ethernet Link Up");
    ESP_LOGI(TAG, "Ethernet HW Addr %02x:%02x:%02x:%02x:%02x:%02x",
             mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
    break;
  case ETHERNET_EVENT_DISCONNECTED:
    ESP_LOGI(TAG, "Ethernet Link Down");
    break;
  case ETHERNET_EVENT_START:
    ESP_LOGI(TAG, "Ethernet Started");
    break;
  case ETHERNET_EVENT_STOP:
    ESP_LOGI(TAG, "Ethernet Stopped");
    break;
  default:
    break;
  }
}

/** Event handler for IP_EVENT_ETH_GOT_IP */
static void got_ip_event_handler(void *arg, esp_event_base_t event_base,
                                 int32_t event_id, void *event_data)
{
  ip_event_got_ip_t *event = (ip_event_got_ip_t *)event_data;
  const esp_netif_ip_info_t *ip_info = &event->ip_info;

  ESP_LOGI(TAG, "Ethernet Got IP Address");
  ESP_LOGI(TAG, "~~~~~~~~~~~");
  ESP_LOGI(TAG, "ETHIP:" IPSTR, IP2STR(&ip_info->ip));
  ESP_LOGI(TAG, "ETHMASK:" IPSTR, IP2STR(&ip_info->netmask));
  ESP_LOGI(TAG, "ETHGW:" IPSTR, IP2STR(&ip_info->gw));
  ESP_LOGI(TAG, "~~~~~~~~~~~");
}

void list_files()
{
  const char *base_path = "/spiffs"; // Указание базового пути к файловой системе SPIFFS
  DIR *dir = opendir(base_path);
  struct dirent *ent;

  if (!dir)
  {
    ESP_LOGE("list_files", "Failed to open dir");
    return;
  }

  while ((ent = readdir(dir)) != NULL)
  {
    printf("Found file: %s\n", ent->d_name);
  }

  closedir(dir);
}

void initial_spiffs()
{
  ret = nvs_flash_init();
  if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
  {
    ESP_ERROR_CHECK(nvs_flash_erase());
    ret = nvs_flash_init();
  }

  // esp_vfs_spiffs_conf_t
  conf = {
      .base_path = "/spiffs",
      .partition_label = NULL,
      .max_files = 5,
      .format_if_mount_failed = true};

  // esp_err_t
  ret = esp_vfs_spiffs_register(&conf);

  if (ret != ESP_OK)
  {
    if (ret == ESP_FAIL)
    {
      ESP_LOGE(TAG, "Failed to mount or format filesystem");
    }
    else if (ret == ESP_ERR_NOT_FOUND)
    {
      ESP_LOGE(TAG, "Failed to find SPIFFS partition");
    }
    else
    {
      ESP_LOGE(TAG, "Failed to initialize SPIFFS (%s)", esp_err_to_name(ret));
    }
    return;
  }
}

void spiffs_format()
{
  // const char *base_path = "/spiffs"; // Указание базового пути к файловой системе SPIFFS
  // DIR *dir = opendir(base_path);
  // struct dirent *ent;

  // if (!dir)
  // {
  //   ESP_LOGE("list_files", "Failed to open dir");
  //   return;
  // }

  // while ((ent = readdir(dir)) != NULL)
  // {
  //   // printf("Found file: %s\n", ent->d_name);
  //   std::remove(ent->d_name);
  // }

  // closedir(dir);
  // std::cout << "Success formatting" << std::endl;
  // esp_vfs_spiffs_unregister(conf.partition_label);
  // initial_spiffs();
  // std::cout << "spiffs_format" << std::endl;
  // esp_spiffs_format(conf.base_path);
}

static void read_json(void)
{

  std::ifstream file("/spiffs/data.json");
  if (!file)
  {
    std::cout << "Ошибка открытия файла" << std::endl;
    return;
  }

  std::string str;
  while (std::getline(file, str))
  {
    std::cout << str << std::endl;
  }
  file.close();

  // std::cout <<doc["plans"][0]["algorithm"]["phases"][0]["stage"]
  //<< std::endl;
}

#define UART_NUM UART_NUM_0 // Выбор номера UART (0 или 1)
#define BUF_SIZE (1024)

void uart_task(void *pvParameter)
{
  uart_config_t uart_config = {
      .baud_rate = 115200,
      .data_bits = UART_DATA_8_BITS,
      .parity = UART_PARITY_DISABLE,
      .stop_bits = UART_STOP_BITS_1,
      .flow_ctrl = UART_HW_FLOWCTRL_DISABLE};

  uart_driver_install(UART_NUM, BUF_SIZE * 2, 0, 0, NULL, 0);
  uart_param_config(UART_NUM, &uart_config);
  uart_set_pin(UART_NUM, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);

  uint8_t *data = (uint8_t *)malloc(BUF_SIZE);

  while (1)
  {
    int len = uart_read_bytes(UART_NUM, data, BUF_SIZE, 20 / pdMS_TO_TICKS(1000));
    if (len > 0)
    {
      // //     // Обработка прочитанных данных
      // //     printf("Прочитано из UART: %.*s", len, data);
      // //     // Добавьте вашу логику обработки команд здесь
      // //     // std::cout<<len<<" "<<data<<std::endl;
      // //     //   if (a != 0)
      // //     //         std::cout << a << std::endl;
      int d = *data - 48;
      std::cout << d << std::endl;
      if (d == 1 || d == -83)
        read_json();
      if (d == 2)
        spiffs_format();
      if (d == 3)
        list_files();
    }
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
  // free(data);
}

bool findJson()
{
  const char *base_path = "/spiffs"; // Указание базового пути к файловой системе SPIFFS
  DIR *dir = opendir(base_path);
  struct dirent *ent;

  if (!dir)
  {
    ESP_LOGE("list_files", "Failed to open dir");
    return false;
  }

  while ((ent = readdir(dir)) != NULL)
  {
    if (ent->d_name == std::string("data.json"))
      return true;
  }
  return false;
}

void json_desearelization()
{

  std::ifstream file("/spiffs/data.json");
  if (!file)
  {
    std::cout << "Ошибка открытия файла" << std::endl;
    return;
  }

  std::string str;
  std::string f;
  uint row = 0;
  uint row_total = 0;
  while (std::getline(file, str))
    ++row_total;
  // std::cout << row_total << std::endl;

  std::ifstream file2("/spiffs/data.json");
  if (!file2)
  {
    std::cout << "Ошибка открытия файла" << std::endl;
    return;
  }
  while (std::getline(file2, str))
  {
    ++row;
    //  std::cout << str << std::endl;
    if (row > 3 && row < row_total)
    {
      //   std::cout << str << std::endl;
      f += str;
    }
  }
  file.close();
  file2.close();

  DeserializationError error = deserializeJson(doc, f);
  if (error)
  {
    printf(("deserializeJson() failed: "));
    printf(error.c_str());
    return;
  }
  else
  {
    there_config = true;
    read_json();
  }
}
// void app_main(void)
extern "C" void app_main()
{
  // esp_err_t
  //  httpd_resp_set_hdr(req, "Location", "/");
  gpio_set_level(gpio_num_t(in1), 1);
  initial_spiffs();

 // connect_wifi();

  // if (wifi_connect_status)
  // {
  //   ESP_LOGI(TAG, "LED Control SPIFFS Web Server is running ... ...\n");
  //   setup_server();
  // }


    ESP_ERROR_CHECK(gpio_install_isr_service(0));
    // Initialize TCP/IP network interface (should be called only once in application)
    ESP_ERROR_CHECK(esp_netif_init());
    // Create default event loop that running in background
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_config_t netif_cfg = ESP_NETIF_DEFAULT_ETH();
    esp_netif_t *eth_netif = esp_netif_new(&netif_cfg);

    spi_bus_config_t buscfg = {
        .mosi_io_num = CONFIG_EXAMPLE_ENC28J60_MOSI_GPIO,
        .miso_io_num = CONFIG_EXAMPLE_ENC28J60_MISO_GPIO,
        .sclk_io_num = CONFIG_EXAMPLE_ENC28J60_SCLK_GPIO,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .data4_io_num = -1,
        .data5_io_num = -1,
        .data6_io_num = -1,
        .data7_io_num = -1,
        .max_transfer_sz = SOC_SPI_MAXIMUM_BUFFER_SIZE,
    };
    ESP_ERROR_CHECK(spi_bus_initialize(spi_host_device_t(CONFIG_EXAMPLE_ENC28J60_SPI_HOST), &buscfg, SPI_DMA_CH_AUTO));
    /* ENC28J60 ethernet driver is based on spi driver */
    spi_device_interface_config_t spi_devcfg = {
        .mode = 0,
        .cs_ena_posttrans = enc28j60_cal_spi_cs_hold_time(CONFIG_EXAMPLE_ENC28J60_SPI_CLOCK_MHZ),
        .clock_speed_hz = CONFIG_EXAMPLE_ENC28J60_SPI_CLOCK_MHZ * 1000 * 1000,
        .spics_io_num = CONFIG_EXAMPLE_ENC28J60_CS_GPIO,
        .queue_size = 20,

    };

    eth_enc28j60_config_t enc28j60_config = ETH_ENC28J60_DEFAULT_CONFIG(spi_host_device_t(CONFIG_EXAMPLE_ENC28J60_SPI_HOST), &spi_devcfg);
    enc28j60_config.int_gpio_num = CONFIG_EXAMPLE_ENC28J60_INT_GPIO;

    eth_mac_config_t mac_config = ETH_MAC_DEFAULT_CONFIG();
    esp_eth_mac_t *mac = esp_eth_mac_new_enc28j60(&enc28j60_config, &mac_config);

    eth_phy_config_t phy_config = ETH_PHY_DEFAULT_CONFIG();
    phy_config.autonego_timeout_ms = 0; // ENC28J60 doesn't support auto-negotiation
    phy_config.reset_gpio_num = -1;     // ENC28J60 doesn't have a pin to reset internal PHY
    esp_eth_phy_t *phy = esp_eth_phy_new_enc28j60(&phy_config);

    esp_eth_config_t eth_config = ETH_DEFAULT_CONFIG(mac, phy);
    esp_eth_handle_t eth_handle = NULL;
    ESP_ERROR_CHECK(esp_eth_driver_install(&eth_config, &eth_handle));

    /* ENC28J60 doesn't burn any factory MAC address, we need to set it manually.
       02:00:00 is a Locally Administered OUI range so should not be used except when testing on a LAN under your control.
    */
    // mac->set_addr(mac, (uint8_t[]){
    //                       0x02, 0x00, 0x00, 0x12, 0x34, 0x56});
    uint8_t macAddr[] = {0x02, 0x00, 0x00, 0x12, 0x34, 0x56};
    mac->set_addr(mac, macAddr);

    // ENC28J60 Errata #1 check
    if (emac_enc28j60_get_chip_info(mac) < ENC28J60_REV_B5 && CONFIG_EXAMPLE_ENC28J60_SPI_CLOCK_MHZ < 8)
    {
      ESP_LOGE(TAG, "SPI frequency must be at least 8 MHz for chip revision less than 5");
      ESP_ERROR_CHECK(ESP_FAIL);
    }

    /* attach Ethernet driver to TCP/IP stack */
    ESP_ERROR_CHECK(esp_netif_attach(eth_netif, esp_eth_new_netif_glue(eth_handle)));
    // Register user defined event handers
    ESP_ERROR_CHECK(esp_event_handler_register(ETH_EVENT, ESP_EVENT_ANY_ID, &eth_event_handler, NULL));
    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_ETH_GOT_IP, &got_ip_event_handler, NULL));

    /* It is recommended to use ENC28J60 in Full Duplex mode since multiple errata exist to the Half Duplex mode */
  #if CONFIG_EXAMPLE_ENC28J60_DUPLEX_FULL
    eth_duplex_t duplex = ETH_DUPLEX_FULL;
    ESP_ERROR_CHECK(esp_eth_ioctl(eth_handle, ETH_CMD_S_DUPLEX_MODE, &duplex));
  #endif

    /* start Ethernet driver state machine */
    ESP_ERROR_CHECK(esp_eth_start(eth_handle));
    example_set_static_ip(eth_netif);

    // led_state = 0;
    ESP_LOGI(TAG, "LED Control Web Server is running ... ...\n");
    // configureWebServer();
    setup_server();
    ESP_LOGI(TAG, "start");

  // GPIO initialization

  gpio_config_t io_conf_26;
  // Настраиваем пин GPIO, например, GPIO_NUM_4 на вывод
  io_conf_26.intr_type = GPIO_INTR_ANYEDGE;
  // GPIO_PIN_INTR_DISABLE;
  io_conf_26.pin_bit_mask = (1ULL << GPIO_NUM_26);
  io_conf_26.mode = GPIO_MODE_OUTPUT;
  gpio_config(&io_conf_26);

  gpio_config_t io_conf_27;
  // Настраиваем пин GPIO, например, GPIO_NUM_4 на вывод
  io_conf_27.intr_type = GPIO_INTR_ANYEDGE;
  // GPIO_PIN_INTR_DISABLE;
  io_conf_27.pin_bit_mask = (1ULL << GPIO_NUM_27);
  io_conf_27.mode = GPIO_MODE_OUTPUT;
  gpio_config(&io_conf_27);

  // while (1)
  // {
  //   Traffic_lights();
  //   //   vTaskDelay(pdMS_TO_TICKS(10));
  // }

  // Use settings defined above to initialize and mount SPIFFS filesystem.
  // Note: esp_vfs_spiffs_register is an all-in-one convenience function.

#ifdef CONFIG_EXAMPLE_SPIFFS_CHECK_ON_START
  ESP_LOGI(TAG, "Performing SPIFFS_check().");
  ret = esp_spiffs_check(conf.partition_label);
  if (ret != ESP_OK)
  {
    ESP_LOGE(TAG, "SPIFFS_check() failed (%s)", esp_err_to_name(ret));
    return;
  }
  else
  {
    ESP_LOGI(TAG, "SPIFFS_check() successful");
  }
#endif

  size_t total = 0, used = 0;
  ret = esp_spiffs_info(conf.partition_label, &total, &used);
  if (ret != ESP_OK)
  {
    ESP_LOGE(TAG, "Failed to get SPIFFS partition information (%s). Formatting...", esp_err_to_name(ret));
    esp_spiffs_format(conf.partition_label);
    return;
  }
  else
  {
    ESP_LOGI(TAG, "Partition size: total: %d, used: %d", total, used);
  }

  // Check consistency of reported partiton size info.
  if (used > total)
  {
    ESP_LOGW(TAG, "Number of used bytes cannot be larger than total. Performing SPIFFS_check().");
    ret = esp_spiffs_check(conf.partition_label);
    // Could be also used to mend broken files, to clean unreferenced pages, etc.
    // More info at https://github.com/pellepl/spiffs/wiki/FAQ#powerlosses-contd-when-should-i-run-spiffs_check
    if (ret != ESP_OK)
    {
      ESP_LOGE(TAG, "SPIFFS_check() failed (%s)", esp_err_to_name(ret));
      return;
    }
    else
    {
      ESP_LOGI(TAG, "SPIFFS_check() successful");
    }
    list_files();
  }
  // obtain_time();

  // time(&now);
  // localtime_r(&now, &timeinfo);

  // Теперь у вас есть текущее реальное время в структуре 'timeinfo'
  // Можете использовать это время по необходимости

  xTaskCreate(uart_task, "uart_task", 1024 * 2, NULL, 5, NULL);
  // xTaskCreatePinnedToCore(Traffic_lights, "Traffic_lights", 1024 * 4, NULL, 3, NULL, 0);
  xTaskCreate(Traffic_lights, "Traffic_lights", 1024 * 4, NULL, 1, NULL);
  //   xTaskCreate(web, "Web", 1024 * 2, NULL, 3, NULL);
}
