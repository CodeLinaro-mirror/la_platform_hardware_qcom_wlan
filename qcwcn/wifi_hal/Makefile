LIBNAME=libwifi-hal-qcom.so.0

CSRC = wifi_hal_ctrl/wifi_hal_ctrl.c

CXXSRCS = \
    list.cpp \
    wifi_hal.cpp \
    common.cpp \
    cpp_bindings.cpp \
    llstats.cpp \
    gscan.cpp \
    gscan_event_handler.cpp \
    rtt.cpp \
    ifaceeventhandler.cpp \
    tdls.cpp \
    nan.cpp \
    nan_ind.cpp \
    nan_req.cpp \
    nan_rsp.cpp \
    wificonfig.cpp \
    wifilogger.cpp \
    wifilogger_diag.cpp \
    ring_buffer.cpp \
    rb_wrapper.cpp \
    rssi_monitor.cpp \
    roam.cpp \
    radio_mode.cpp \
    tcp_params_update.cpp \
    wifihal_vendor.cpp

SOURCES = \
    $(CSRC) \
    $(CXXSRCS)

COBJECTS := $(CSRC:.c=.o)
CXXOBJECTS := $(CXXSRCS:.cpp=.o)

CFLAGS += -c -fPIC
CXXFLAGS += -c -fPIC
CPPFLAGS += -Iwifi_hal_ctrl
CPPFLAGS += -DENABLE_LOG
LDFLAGS += -lcutils -lqti_log_util -ldl -lcld80211 -lcrypto -lnl-3
LDFLAGS += -shared -Wl,-soname,$(LIBNAME)

$(LIBNAME): $(COBJECTS) $(CXXOBJECTS)
	$(CXX) $^ -o $@ $(LDFLAGS)

clean:
	rm -rf *.o *.so*

$(COBJECTS): %.o: %.c
	$(CC) $< -o $@ $(CFLAGS) $(CPPFLAGS)

$(CXXOBJECTS): %.o: %.cpp
	$(CXX) $< -o $@  $(CXXFLAGS) $(CPPFLAGS)
