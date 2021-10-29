module george(o, x, y);

output o;
input x, y;

wire or_wire, not_wire;

or(or_wire, x, y);
not(not_wire, y);
and1 x1(o, or_wire, not_wire);


endmodule 