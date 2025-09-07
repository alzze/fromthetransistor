module blink(input wire clk, output reg led);
  reg [18:0] cnt = 0;
  always @(posedge clk) begin
    cnt <= cnt + 1;
    led <= cnt[18];
  end
endmodule
