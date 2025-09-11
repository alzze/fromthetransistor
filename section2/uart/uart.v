module uart( input wire clk, input wire rst, input wire rx,input wire start, input wire [7:0] data_in, output wire tx, output wire [7:0] data_out, output wire busy, output wire data_valid);
  wire baud_tick;

  baud_rate #(
    .CLOCK(50000000), 
    .BAUD(9600)      
  ) baud_gen (
    .clk(clk),
    .rst(rst),
    .baud_tick(baud_tick)
  );

  uart_rx uart_receiver (
    .baud_tick(baud_tick),
    .rst(rst),
    .rx(rx),
    .data_out(data_out)
  );

  uart_tx uart_transmitter (
    .baud_tick(baud_tick),
    .rst(rst),
    .start(start),
    .data_in(data_in),
    .tx(tx),
    .busy(busy)
  );

endmodule

