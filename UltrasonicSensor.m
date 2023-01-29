clear all;
clc;
%To set serial port

priorPorts=instrfind;
delete(priorPorts);
clear priorPorts ;

samples = 500;

PSoC=serial('COM13','BaudRate',115200,'Parity','none','DataBits',8,'StopBits',1); %serial port parameters

set(PSoC,'InputBufferSize',6); %buffer length in bytes, default:512 bytes
set(PSoC,'Terminator','V');

fopen(PSoC); %opens serial port

counter = 1;

fprintf(PSoC,'%c','l'); %character that initiates the process
%pause(0.5); %delay to sample

%set = [];
%ps=0;

while counter <= samples
%while (1)
    data = fscanf(PSoC,'%f')' 
    distance(counter)=data(1);
%    if(data ~= ps)
%        set=[set,data]
%        ps = data
    counter = counter + 1;
    
    if counter >= samples
       counter = 1;
    end
end
fclose(PSoC);
delete(PSoC);