<?php 
include("lib/class.curl.inc");
include("lib/peanutcore.inc");
include("lib/messagehub.inc");
include("lib/irc.inc");
$peanut = new Peanut();
while(true){
	$peanut->main();
	$peanut->delay();
}