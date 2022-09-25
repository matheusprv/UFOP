// Felipe Braz, Mariana, Matheus Peixoto, Nícolas Expedito ,Pedro Henrique, Vinicíus 
module ventilador(a,b,c,d,s1,s2);
   input a,b,c,d;
   output s1, s2;
   
   assign s1 = a;
   assign s2 = (~a&c&d) | b;
   
endmodule

module simulador;

    reg a,b,c,d;
    wire s1, s2;
    
    initial
        begin
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        end
        
    always
        begin
        #1 {a, b, c, d} = {a, b, c, d} + 1;
        end
        
    initial
        begin
        #15 $finish;
        end
        
    initial
        begin
        $display("tempo\t A\t B\t C\t D\t S1\t S2\t");
        $monitor("%5d\t %b\t %b\t %b\t %b\t %b\t %b\t", $time, a, b, c, d, s1, s2);
        end
        
    ventilador sim(.a(a), .b(b), .c(c), .d(d), .s1(s1), .s2(s2));
    
endmodule
