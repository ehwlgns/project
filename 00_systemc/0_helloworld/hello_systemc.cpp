#include <iostream>
#include <systemc.h>
SC_MODULE(hello_systemc){
    sc_in_clk iclk;
    SC_CTOR(hello_systemc){
        SC_METHOD(main_method);
        sensitive << iclk.neg();
        dont_initialize();
    }
    void main_method(void) {
        std::cout << sc_time_stamp()
                  << "hello_world"
                  << std::endl;
    }

};

int sc_main(int argc, char* argv[]){
    const sc_time t_PERIOD (8,SC_NS);
    sc_clock clk ("clk", t_PERIOD);
    hello_systemc ihelloworld ("ihelloworld");
    ihelloworld.iclk(clk);
    sc_start(10,SC_NS);
    return 0;
}
