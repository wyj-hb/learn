a = length(new_X);
result = zeros(a,1);
for i=1:a
     result(i) = myNeuralNetworkFunction(net,new_X');
end

