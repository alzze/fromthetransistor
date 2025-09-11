module uart_tx(input wire baud_tick, input wire rst, input wire start, input wire [7:0] data_in, output reg tx, output reg busy);
  typedef enum reg[1:0]{
    IDLE = 2'b00,
    START = 2'b01,
    DATA = 2'b10,
    STOP = 2'b11
   } states;

   reg [1:0] current_state = IDLE;
   reg [7:0] index = 0;

   always @(posedge baud_tick or posedge rst) begin
     if (rst) begin
       current_state <= IDLE;
       index <= 0;
       tx <= 1;
       busy <= 0;
     end else begin
       case (current_state)
         IDLE: begin
           tx <= 1;
           busy <= 0;
           if (start)begin
            index <= 0;
            busy <= 1;
            current_state <= START;
           end
         end
         START: begin
           tx <= 0;
           current_state <= DATA;
         end
         DATA: begin
           tx <= data_in[index];
           index <= index + 1;
           if (index == 7)begin
             current_state <= STOP;
           end
         end
         STOP: begin
           tx <= 1;
           current_state <= IDLE;
         end
         default: current_state <= IDLE;
       endcase
     end
   end
endmodule
