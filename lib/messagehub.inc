<?php 

class MessageHub{
	function __construct(){
		
	}
	function read(){
		$buffer = '';
		Peanut::Debug("Read ".count($buffer)." Bytes from MessageHub");
	}
	function write(){
		
	}
}

Peanut::RegisterTransport("MessageHub","MessageHub interconnect");