set ns [new Simulator]

set tracefile [open lab5.tr w]
$ns trace-all $tracefile

set namfile [open lab5.nam w]
$ns namtrace-all $namfile

proc finish {} {
global ns tracefile namfile
$ns flush-trace
close $tracefile
close $namfile
exec nam lab5.nam &
exit 0
}
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

$ns duplex-link $n0 $n2 10.0Mb 1ms DropTail
$ns queue-limit $n0 $n2 10
$ns duplex-link $n1 $n2 10.0Mb 1ms DropTail
$ns queue-limit $n1 $n2 10
$ns simplex-link $n2 $n3 10.0Mb 1ms DropTail
$ns queue-limit $n2 $n3 10
$ns simplex-link $n3 $n2 10.0Mb 1ms DropTail
$ns queue-limit $n3 $n2 10
$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns simplex-link-op $n2 $n3 orient right
$ns simplex-link-op $n3 $n2 orient left

set lan [$ns newLan "$n3 $n4 $n5" 0.5Mb 40ms LL Queue/DropTailMAC/802_3 Channel]
set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0

set sink4 [new Agent/TCPSink]
$ns attach-agent $n4 $sink4
$ns connect $tcp0 $sink4
$tcp0 set packetSize_ 1500

set udp1 [new Agent/UDP]
$ns attach-agent $n1 $udp1

set null5 [new Agent/Null]
$ns attach-agent $n5 $null5
$ns connect $udp1 $null5
$udp1 set packetSize_ 1500

set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0

$ns at 1.0 "$ftp0 start"
$ns at 10.0 "$ftp0 stop"

set cbr1 [new Application/Traffic/CBR]
$cbr1 attach-agent $udp1
$cbr1 set rate_ 5.0Mb
$ns at 1.0 "$cbr1 start"
$ns at 10.0 "$cbr1 stop"

$ns at 11.0 "finish"

$ns run
