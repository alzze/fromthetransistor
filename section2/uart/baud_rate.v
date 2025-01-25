module baud_rate(input wire clk, input wire rst, output reg baud_tick);
  parameter CLOCK = 50000000; 
  parameter BAUD = 9600;
  parameter DIVISOR = CLOCK / BAUD;

  reg [15:0] counter = 0;

  always @(posedge clk or posedge rst) begin
    if (rst) begin
      counter <= 0;
      baud_tick <= 0;
    end else begin
      if (counter == DIVISOR / 2 -1) begin
        baud_tick <= ~baud_tick;
        counter <= 0;
      end else begin
        counter <= counter + 1;
      end
    end
  end
endmodule 
