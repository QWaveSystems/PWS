
#ifndef QWAVE_CONNECTOR_H
#define QWAVE_CONNECTOR_H

#include "ESP8266WiFi.h"
#include <functional>

#ifdef ESP8266
extern "C" {
#include "user_interface.h"
}
#endif

#ifdef WIFI_DEBUG_MODE
    #define WIFI_DEBUG_PRINTER Serial
    #define WIFI_DEBUG_PRINT(...) { WIFI_DEBUG_PRINTER.print(__VA_ARGS__); }
    #define WIFI_DEBUG_PRINTLN(...) { WIFI_DEBUG_PRINTER.println(__VA_ARGS__); }
#else
    #define WIFI_DEBUG_PRINT(...) { }
    #define WIFI_DEBUG_PRINTLN(...) { }
#endif

// TYPES
// typedef enum {
//     WL_NO_SHIELD        = 255,   // for compatibility with WiFi Shield library
//     WL_IDLE_STATUS      = 0,
//     WL_NO_SSID_AVAIL    = 1,
//     WL_SCAN_COMPLETED   = 2,
//     WL_CONNECTED        = 3,
//     WL_CONNECT_FAILED   = 4,
//     WL_CONNECTION_LOST  = 5,
//     WL_DISCONNECTED     = 6
// } wl_status_t;


class QwaveConnector
{
public:
    typedef std::function<void(const void*)> wifi_callback_t;

    int SMART_CONFIG_PIN = 0;
    uint32_t counter = 0;
    QwaveConnector(String ssid, String password);
    QwaveConnector();
    ~QwaveConnector();
    void init_config(String, String);
    void connect();
    void begin();
    int loop(bool iloop);

    void smartconfig_check(uint8_t pin);
    void enter_smartconfig_mode();
    String get(String key);
    String SSID();
    String psk();
	
	String httpGET(const int httpPort, String HOST, String URI);
	String httpsGET(String HOST, String URI);
	String httpPOST(const int httpPort, String HOST, String URI, String DATA);
	String httpsPOST(String HOST, String URI, String DATA);
	
	void httpUpload_Open(const int httpPort, String HOST, String URI, String name, String filename, uint32_t image_len);
    void httpUpload_Send(unsigned char* buffer, uint32_t length);
    void httpUpload_Close();
	
	void httpsUpload_Open(String HOST, String URI, String name, String filename, uint32_t data_len);
    void httpsUpload_Send(unsigned char* buffer, uint32_t length);
    void httpsUpload_Close();

    // CALLBACKS
    void on_disconnected(wifi_callback_t callback = NULL);
    void on_connected(wifi_callback_t callback = NULL);
    void on_connecting(wifi_callback_t callback = NULL);
    void on_smartconfig_processing(wifi_callback_t callback = NULL);
    void on_smartconfig_waiting(wifi_callback_t callback = NULL);
    void on_smartconfig_done(wifi_callback_t callback = NULL);

protected:

private:
    String _ssid = "";
    String _password = "";
    String _mac = "";
	String boundary = "";

    wifi_callback_t _user_on_disconnected = NULL;
    wifi_callback_t _user_on_connected  = NULL;
    wifi_callback_t _user_on_connecting = NULL;
    wifi_callback_t _user_on_smartconfig_waiting = NULL;
    wifi_callback_t _user_on_smartconfig_processing = NULL;
    wifi_callback_t _user_on_smartconfig_done = NULL;    

    unsigned long _retries = 0;
    unsigned long prev_millis;

    void _on_smartconfig_done();
    void _on_smartconfig_processing();
    void _on_smartconfig_waiting();
    void _connect(bool iloop);
};

extern QwaveConnector *wifi;
extern WiFiClient httpupload;
extern WiFiClientSecure httpsupload;

#endif//QWAVE_CONNECTOR_H
