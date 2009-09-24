<?php 

class irc{
	function __construct(){
		
	}
	function read(){
		$buffer = '';
		Peanut::Debug("Read ".count($buffer)." Bytes from IRC");
	}
	function write(){
		
	}
}

Peanut::RegisterTransport("irc","IRC interconnect");