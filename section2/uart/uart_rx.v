module uart_rx(input wire baud_tick, input wire rst, input wire rx, output reg[7:0] data_out);
  typedef enum reg[2:0]{
      IDLE = 3'b000,
      START = 3'b001,
      DATA = 3'b010,
      STOP = 3'b011,
      COMPLETE = 3'b100
  }states;

  reg [2:0] current_state = IDLE;
  reg [2:0] index = 0;
  reg [7:0] data_buffer = 0;

  always @(posedge baud_tick or posedge rst)begin
    if (rst)begin
      current_state <= IDLE;
      index <= 0;
      data_buffer <= 0;
      data_out <= 0;
    end else begin
      case (current_state)
        IDLE: begin
          if (rx == 0)
            current_state <= START;
        end
        START: begin
          if (rx == 0) begin
            index <= 0;
            current_state <= DATA;
          end else begin
            current_state <= IDLE;
          end
        end
        DATA: begin
          data_buffer[index] <= rx;
          index <= index + 1;
          if (index == 7) begin
            current_state <= STOP;
          end
        end
        STOP: begin
          if(rx == 1)begin
            current_state <= COMPLETE;
          end else begin
            current_state <= IDLE;
          end
        end
        COMPLETE: begin
          data_out <= data_buffer;
          current_state <= IDLE;
        end
        default: current_state <= IDLE;
      endcase
    end
  end
endmodule
