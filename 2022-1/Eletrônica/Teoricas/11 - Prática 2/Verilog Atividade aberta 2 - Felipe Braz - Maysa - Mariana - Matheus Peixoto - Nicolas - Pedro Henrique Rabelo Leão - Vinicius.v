//Felipe Braz Marques, Maysa Roberta Carneiro Pires, Mariana Macedo Santos, 
//Matheus Peixoto Ribeiro Vieira, Nicolas Expedito Lana Mendes, 
//Pedro Henrique Rabelo Leão de Oliveira, Vinicius Nunes dos Anjos 
module controle(S, V, velocidade, motorSelecionado);

    input [1:0] S;
    input [3:0] V;

    output reg [7:0] velocidade; 
    output reg [2:0] motorSelecionado;

    always @ (V)
        begin
            if(V==0) velocidade = 8'b00000000;
            else if(V<3) velocidade = 8'b00001111; 
            else if(V<8) velocidade = 8'b00110011;
            else velocidade = 8'b11000011;
        end

    always @ (S)
        begin 
            motorSelecionado = S+1;
        end

endmodule


module simulacao;
    reg [1:0] S;
    reg [3:0] V;
    wire [7:0]velocidade;
    wire [2:0]motorSelecionado;

    initial begin
        S = 0;
        V = 0;
    end

    always 
        begin
        #1
            V = V+1;
            if(V==0)
              begin
                  S = S+1;
              end
        end
    
    always
        begin
        #1
            if(V==15 && S==3)
            begin
                $finish;
            end
        end


    initial begin
        $display("Motor Velocidade");
        $monitor("  %d    %b", motorSelecionado, velocidade);
    end
        
    
    controle teste(.S(S), .V(V), .velocidade(velocidade), .motorSelecionado(motorSelecionado));

endmodule

/*
Motor Velocidade
  1    00000000
  1    00001111
  1    00110011
  1    11000011
  2    00000000
  2    00001111
  2    00110011
  2    11000011
  3    00000000
  3    00001111
  3    00110011
  3    11000011
  4    00000000
  4    00001111
  4    00110011
  4    11000011
*/