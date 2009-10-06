<?php 

class MessageHub{
	static $server = "messagehub.dev";
	static $interface = "/";
	static $username = "Johnny";
	static $password = "Rocketpants";
	
	private $curl;
	
	function __construct(){
		$this->curl = new curl();
		$this->connect();
	}
	
	function read(){
		$buffer = '';
		Peanut::Debug("Read ".strlen($buffer)." Bytes from MessageHub");
	}
	
	function write(){
		
	}
	
	function connect(){
		$responce = $this->curl->post(self::$server.self::$interface,
			array('username'=>self::$username,'password'=>self::$password)
		);
		Peanut::Debug("READ: {$responce['body']}");
		Peanut::Debug("Connecting to server, read ".strlen($responce)." Bytes from MessageHub");
		if($responce['body'] == "OK"){
			
		}else{
			Peanut::Debug("Failed to connect to server. Retrying in 2 seconds.");
			Peanut::AddDelayedEvent(2,array($this,"connect"));;
			
		}
		
	}
}

Peanut::RegisterTransport("MessageHub","MessageHub interconnect");