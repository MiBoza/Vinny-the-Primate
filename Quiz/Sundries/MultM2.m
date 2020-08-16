function [product] = MultM2(a,b)
product = 0;
while(b > 0)
    if(bitget(b, 1) == 1)
        product = bitxor(product, a);
    end
    b = bitshift(b, -1);
    a = bitshift(a, 1);
end

while(product > 7)
    temp = product;
    count = -4;
    while(temp > 0)
        temp = bitshift(temp, -1);
        count = count + 1;
    end
    if(count >= 0)
        product = bitxor(product, bitshift(11, count));
    end
end
end