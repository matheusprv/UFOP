module DecTeclado(t,s,p); //modulo Decodificador de Teclado
   
    input      [9:0] t;
    output reg [3:0] s;
    output reg       p;
   
    always @(*)
        begin
            case(t)
                10'b0000000001: s=1;
                10'b0000000010: s=2;
                10'b0000000100: s=3;
                10'b0000001000: s=4;
                10'b0000010000: s=5;
                10'b0000100000: s=6;
                10'b0001000000: s=7;
                10'b0010000000: s=8;
                10'b0100000000: s=9;
                10'b1000000000: s=10;
                default: s= 0;
            endcase // case (t)
        end // always @ (*)
   
    always @(s) 
        //Sempre que o valor de C modificar, alterar o valor de s para s menos 1
        begin
            if(s != 0) 
                s = s-1;
        end
   
    always @(*)
        begin
            p = (|t) ? 1 : 0; //reducao OR -> verifica se existe algum botao pressionado
        end
   
endmodule // DecTeclado
