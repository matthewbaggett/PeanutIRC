<?php 
/**
 * Peanut communication 'droid.
 * @author MB
 */
class Peanut{
	
	static $transports;	//array of transports loaded to read/write to
	static $oTransports;
	
	private $loopsMaxPerSecond = 3;
	
	/**
	 * Constructor.
	 * @return none
	 */
	function __construct(){
		Peanut::static_construct();
		foreach(Peanut::getTransports() as $transportDef){
			$transportClass = $transportDef['class'];
			$oTransport = new $transportClass();
			Peanut::addTransportObject($oTransport);
		}
	}
	
	static function static_construct(){
		//self::$transports = array();
	} 
	
	/**
	 * Main loop. 
	 * Checks for updates on all connections, processes as neccisary, 
	 * then fires off messages on all connections if there is anything cued.
	 * @author MB
	 * @return false
	 */
	function main(){
		$this->readTransports();
		$this->processMessageBuff();
		$this->writeTransports();
		Peanut::Debug("Main loop complete.");
		return false;
	}
	
	function readTransports(){
		$oTransports = Peanut::getTransportObjects();
		foreach($oTransports as $oTransport){
			$readBuffer = $oTransport->read();
		}
	}
	function processMessageBuff(){
		
	}
	function writeTransports(){
		
	}
	
	/**
	 * Delay loop
	 * Fires when the main loop completes to prevent the main 
	 * loop starting again, maxing out the CPU... Hacky, but 
	 * I can't think of a better, simple way of performing this.
	 * @author MB
	 * @return false
	 */
	function delay(){
		usleep(1000000 / $this->loopsMaxPerSecond);
		return false;
	}
	
	/**
	 * RegisterTransport
	 * 
	 * Function to register a transport with the peanut controller
	 * @author MB
	 * @param $transportClass - The name of the class in question
	 * @param $displayName - A nice name to give the module. So you 
	 * could have a class of 'irc' and a displayname of 'IRC interconnect' 
	 * which looks smarter. And more friendly.
	 * @return unknown_type
	 */
	static function RegisterTransport($transportClass,$displayName = null){
		if($displayName === null){
			$displayName = $transportClass;
		}
		self::$transports[] = array("class"=>$transportClass,"name"=>$displayName);
		Peanut::Debug("Registered a transport {$displayName}");
	}
	/**
	 * AddTransportObject
	 * @param $object
	 * @return unknown_type
	 */
	static function addTransportObject($object){
		self::$oTransports[] = $object;
		return true;
	}
	/**
	 * GetTransports
	 * @return unknown_type
	 */
	static function getTransports(){
		return self::$transports;
	}
	
	static function getTransportObjects(){
		return self::$oTransports;
	}
	
	/**
	 * Debug
	 * spits out debug in a consistant manner.
	 * @param $message
	 * @return unknown_type
	 */
	static function Debug($message){
		$message = trim($message);
		$dateTime = date("m/d/y@H:i:s");
		echo "[{$dateTime}] $message\n";
	}
}