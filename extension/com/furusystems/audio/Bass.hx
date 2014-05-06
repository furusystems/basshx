package com.furusystems.audio;
import cpp.Lib;

/**
 * ...
 * @author Andreas Rønning
 */

 
class Bass
{
	
	static public function startMusic(path:String):Void {
		start(path);
	}
	static public function endMusic():Void {
		stop();
	}
	static var start = Lib.load("OpenFL-BASS", "startMusic", 1);
	static var stop = Lib.load("OpenFL-BASS", "endMusic", 0);
	
}