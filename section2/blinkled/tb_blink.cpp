#include "Vblink.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char** argv){
  Verilated::commandArgs(argc, argv);
  Vblink* dut = new Vblink;

  dut -> clk = 0;
  dut -> led = 0;

  const int cycles = 10000000;
  for(int i = 0; i< cycles; i++){
    dut -> clk = !dut -> clk;
    dut -> eval();

    if(dut -> clk){
      std::cout << " LED: " << (int)dut -> led << std::endl;
    }
  }
  delete dut;
  return 0;
}
