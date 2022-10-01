module SOMASUB(A,B,op,R,zero,sinal, bit_overflow);

  input [3:0] A,B;

  output reg bit_overflow;

  input op;

  output reg [3:0] R;

  output zero,sinal;

  assign sinal=R[3];

  assign zero=~(|R);

  always @(*)

    begin

      if(op)
        begin
          {bit_overflow, R} = A-B;
        end

      else
        begin
          {bit_overflow, R} = A+B;
        end

    end

endmodule // SOMASUB



module teste;

  reg [3:0] A, B; 
  reg op;
  wire bit_overflow, zero, sinal;
  wire [3:0] R;

  initial
    begin
      //Começando o A de 1, pois a soma de 0 + B = B
      //Começando o B com 7 para visualizar mais rapidamente o overflow
      A = 1;
      B = 7;
    end
  
  always 
  #1
    begin
        A = A+1;
        if(A==0)
          begin
              B = B+1;
          end
    end
    
    always
        begin
        #1
            if(B==15 && A==15)
            begin
                $finish;
            end
        end


  initial 
    begin
      $display("operação(A+B) overflow resultado");
      $monitor("%d + %d =        %b     %b\n", A, B, bit_overflow, R);
    end

  SOMASUB test(.A(A),.B(B),.op(op),.R(R),.zero(zero),.sinal(sinal), .bit_overflow(bit_overflow));

endmodule

