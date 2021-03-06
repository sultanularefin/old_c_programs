/*
Copyright (c) 2012, comScore Inc. All rights reserved.
version: 5.0.3
*/

if (typeof(COMSCORE) == "undefined") {
	var COMSCORE = {};
}


if (typeof COMSCORE.SiteRecruit == "undefined") {
	COMSCORE.SiteRecruit = {
		version: "5.0.3",
	
		configUrl: "broker-config.js",	// full url to broker config
	
		builderUrl: "builder.js",		// full url to invitation builder
		
		allowScriptCaching: false,
	
		CONSTANTS: {
			COOKIE_TYPE: { ALREADY_ASKED: 1, DD_IN_PROGRESS: 2},
			STATE_NAME: { IDLE: "IDLE", DDINPROGRESS: "DDINPROGRESS"}
		}
		
	};

	COMSCORE.SiteRecruit.Utils = ( function() {
		//private
		var _sr = COMSCORE.SiteRecruit;
		
		// public methods and properties
		return {
			location: document.location.toString(),
				
			loadScript: function(url, loadFresh) {
				// append if load freshis called, do not append if scripcaching is allowed
				if (loadFresh && !_sr.allowScriptCaching) {
					url = _sr.Utils.appendQueryParams(url, (new Date()).getTime());
				}
				
				var s = document.createElement("script");
				s.src = url;
				document.body.appendChild(s);
			},
			
			getBrowser: function() {
				var b = {};
				
				b.name = navigator.appName;
				b.version = parseInt(navigator.appVersion, 10);
				
				// Check for Internet Explorer based browsers.
				if (b.name == "Microsoft Internet Explorer") {
					if (b.version > 3) {
						var ua = navigator.userAgent.toLowerCase();
						if (ua.indexOf("msie 5.0") == -1) {
							b.ie = true;
							
						}
						
						if (ua.indexOf("msie 7") != -1) {
							b.ie7 = true;
							
						}
					}
				}
				
				// Check for Mozilla based browsers.
				if (b.name == "Netscape" || b.name == "Opera") {
					if (b.version > 4) {
						b.mozilla = true;
						
					}
				}
				
				return b;
				
				/* compact version!!!, does it match sr4 behavior?
				b.xpath = !!(document.evaluate);
				if (window.ActiveXObject) {
					b.ie = b[window.XMLHttpRequest ? "ie7" : "ie6"] = true;
					
					COMSCORE.log("browser is IE, " + b.ie7 ? "7" : "6");
				}
				else if (document.childNodes && !document.all && !navigator.taintEnabled) {
					b.webkit = b[b.xpath ? 'webkit420' : 'webkit419'] = true;	
					
					COMSCORE.log("browser is safari");
				}
				else if (document.getBoxObjectFor != null) {
					b.gecko = true;	// mozilla/firefox
				}
				*/
			},
			
			/**
			 * Used for firing a web beacon, loads an image behind the scenes.
			 * @param {Object} url Url of the image request
			 */
			 fireBeacon: function (url) {
				setTimeout(function() {
					if (url.indexOf('?') == -1) {
						url += (/\?/.test(url) ? '&' : '?') + (new Date()).getTime();
					}
					else
					{
						url += '&' + (new Date()).getTime();
					}
											
					var i = new Image();
				
					
					
					i.src = url;			
				}, 1);
			},
			
			appendQueryParams: function(url, params) {
				if (url == null || params == null) {
					
				}
				//params = encodeURIComponent(params);
				if (!url) {
					return params;
				}
				else {
					url = url.replace('?', '') + "?";
				
					if (params) {
						url += params.toString().replace('?', '');
					} 
					
					return url;
				}
			},
			
			getRandom: function(num) {
				// Custom random number generator.
		        var n = 1000000000;
		        
		        function ugen(old, a, q, r, m) {
		            var t = Math.floor(old / q);
		            t = a * (old - (t * q)) - (t * r);
		            return Math.round((t < 0) ? (t + m) : t);
		        }
		        
		        var m1 = 2147483563, m2 = 2147483399, a1 = 40014, a2 = 40692, q1 = 53668, q2 = 52774, r1 = 12211, r2 = 3791, x = 67108862;
		        var g2 = (Math.round(((new Date()).getTime() % 100000)) & 0x7FFFFFFF), g1 = g2;
	 			var shuffle = [32], i = 0;
		        
		        for (; i < 19; i++) {
		            g1 = ugen(g1, a1, q1, r1, m1);
		        }
		        for (i = 0; i < 32; i++) {
		            g1 = ugen(g1, a1, q1, r1, m1);
		            shuffle[31 - i] = g1;
		        }
		        g1 = ugen(g1, a1, q1, r1, m1);
		        g2 = ugen(g2, a2, q2, r2, m2);
		        var s = Math.round((shuffle[Math.floor(shuffle[0] / x)] + g2) % m1);
		    
				var rand = Math.floor(s / (m1 / (n + 1))) / n;
				
				// if passed arg, return number between 0 and num, else return float
				//switched these 2 does it make sense?
				if (typeof(num) == "undefined") {
					
					return rand;
				}
				else {
					
					return Math.floor(rand*(num+1));
				}
			},
			
			getExecutingPath: function(filename) {
				var tags = document.getElementsByTagName("script");
				for (var i = tags.length - 1; i >= 0; i--) {
					var src = tags[i].src;
				
					this.scriptUrl = src;
				
					if (src.indexOf("/" + filename) != -1)	{				
						return src.replace(/(.*)(\/.*)$/, '$1/');
					}
				}
			},
			
			JSONDeserialize: function(str){
				try {
					if (str === "") str = '""'; 
					eval("var p=" + str + ";"); 
					return p; 
				}
				catch (e)
				{
					return null;
				}
			},
			
			JSONSerialize: function (obj) { 
				try {
					var t = typeof (obj); 
					if (t != "object" || obj === null) { 
				 
						if (t == "string") obj = '"'+obj+'"'; 
						return String(obj); 
				 
					} 
					else { 
				 
						var n, v, json = [], arr = (obj && obj.constructor == Array); 
				 
						for (n in obj) { 
							v = obj[n]; t = typeof(v); 
				 
				            if (t != "function"){ 
							    if (t == "string") v = '"'+v+'"'; 
							    else if (t == "object" && v !== null) v = this.JSONSerialize(v); 
    				 
							    json.push((arr ? "" : '"' + n + '":') + String(v)); 
							}
						} 
				 
						return (arr ? "[" : "{") + String(json) + (arr ? "]" : "}"); 
					}
				}		
				catch(e){
					return "";
				}
			} 
		};
	} )();
	
	/*
 Basic Cookie Functionality
 */
 COMSCORE.SiteRecruit.Utils.UserPersistence = {
	maxNumberOfPids : 6,
		//The maximum number of pids allowed at any time in the 'surveys' attribute
	CONSTANTS: {
			STATE_NAME: { IDLE: "IDLE", DDINPROGRESS: "DDINPROGRESS"}
	},
	getCookieName: function(){
			//Get default cookie option from broker if found
			var c;
			if (COMSCORE.SiteRecruit.Broker && COMSCORE.SiteRecruit.Broker.config){
				c = COMSCORE.SiteRecruit.Broker.config.cookie;
				if (c.name){
					return c.name;	
				}
			}
			return "";
	 },
	
	getDefaultCookieOptions: function(){
			var ret= { path: "/", domain: "" };
			return ret;
	 },
	 
	 getVendorId: function(){
			var ret= 1;
			return ret;
	 },
	
	createCookie: function(key, value, options) {
		
		
		value = escape(value);
		
		if (options.duration && options.duration < 0) {
			var date = new Date();
			date.setTime(date.getTime() + options.duration * 24 * 60 * 60 * 1000);
			value += "; expires=" + date.toGMTString();
		}
		else{
			var date = new Date();
			date.setTime(date.getTime() + 10 * 365 * 24 * 60 * 60 * 1000);
			value += "; expires=" + date.toGMTString();
		}
		
		if (options.path) {
			value += "; path=" + options.path;
		}				
		else {
			
		}
						
		if (options.domain) {
			value += "; domain=" + options.domain;
		}
						
		if (options.secure) {
			value += "; secure";
		}
		if (options.graceperiod) {
			value += "; graceperiod=" + options.graceperiod; 
		}
		
		document.cookie = key + "=" + value;

		return true;
	},

	getCookieValue: function(key) {
		var value = document.cookie.match("(?:^|;)\\s*" + key + "=([^;]*)");
		return value ? unescape(value[1]) : false;
	},
	
	removeCookie: function(name, options) {
		
		
		options = options || {};
		options.duration = -999;
		
		this.createCookie(name, "", options);
	},
	
	createUserObj: function(params){
			/*
			{
				version:<Site Recruit version>,
				state:{
				            name:<State Name>,
				            url: <url>,
				            timestamp:<datetime>
				            },
				lastinvited: <datetime>,
				userid: <date>+<random>,
				vendorid: <assigned to comscore >,
				surveys: ["pid","pid",....]
			}

			STATES:
			not in progress/idle
			dd in progress
			edd
			*/
			
			var date = new Date();
			var inputpid = params.pid;
			var inputurl = params.url;
			var inputstate = this.CONSTANTS.STATE_NAME.IDLE;
			if (params.statename){
				 inputstate = params.statename;
			}
			var inputtimestamp = date.getTime();
			if (params.timestamp){
				 inputtimestamp = params.timestamp;
			}
			var inputcookiename = this.getCookieName();
			if (params.cookiename){
				 inputcookiename = params.cookiename;
			}
			if (!params.cookieoptions){
				 params.cookieoptions = this.getDefaultCookieOptions();
			}
			
			var userObj = {};
			userObj.version = "5.0";
			userObj.state = {};
			userObj.state.name = inputstate;
			userObj.state.url = inputurl;
			userObj.state.timestamp = inputtimestamp;
			userObj.lastinvited = inputtimestamp;
			userObj.userid = date.getTime().toString() + Math.floor(Math.random()*9999999999999999).toString() ;
			userObj.vendorid = this.getVendorId();
			userObj.surveys = new Array();
			userObj.surveys.push(inputpid);
			userObj.graceperiod = 5;
			
			var cookieString = COMSCORE.SiteRecruit.Utils.JSONSerialize(userObj);
			
			this.createCookie(inputcookiename,cookieString,params.cookieoptions)
			return userObj;
			
	},
	
	/* Start Public Functions*/
	setUserObj: function(params){
			/*
				Public function to set values for the user object
			*/
			
			var inputpid, inputurl, inputstate, inputtimestamp;
			var inputcookiename, inputgraceperiod, inputtrackertimestamp;
			var date;
			
			var userObj = this.getUserObj(params);
			if (!userObj)
			{
				userObj = this.createUserObj(params);
			}
	
			date = new Date();
			
			//MP: default values
			inputtimestamp = 0;//date.getTime();
			inputcookiename = this.getCookieName();
			inputgraceperiod = 5;
			inputtrackertimestamp = 0;
			inputstate = this.CONSTANTS.STATE_NAME.IDLE; 
				
			//MP: pid and url are directly read from the input object
			inputpid = params.pid;
			
			if (params.url) {
				inputurl = params.url;
			}
			else if (userObj.state.url) {
				inputurl = userObj.state.url;
			}
			
			/**MP:Read values from params object, if not set, read from current cookie (preserve existent value)**/
			
			//MP:state should always be explicitly set, if not, state value will be taken from current cookie
			if (params.statename){
				 inputstate = params.statename;
			} 
			else if (userObj.state && userObj.state.name) {
				inputstate = userObj.state.name
			}
			
			if (params.timestamp) {
				inputtimestamp = params.timestamp;
			}
			else if (userObj.state && userObj.state.timestamp) {
				inputtimestamp = userObj.state.timestamp;
			}
			
			if (params.cookiename){
				 inputcookiename = params.cookiename;
			}
				//MP: cookiename is always passed on the params object
			
			if (!params.cookieoptions){
				 params.cookieoptions = this.getDefaultCookieOptions();
			}
			//MP: cookieoptions do not exist in the userObject, if those values need to be preserved, they should be explicitly read here, one by one
			
			
			if (params.graceperiod) {
				inputgraceperiod = params.graceperiod;
			}
			else if (userObj.graceperiod) {
				inputgraceperiod = userObj.graceperiod;
			}
			//MP: graceperiod is only set once, from then on, it should be preserved
			
			if (params.trackertimestamp)
			{
				inputtrackertimestamp = params.trackertimestamp
			}
			else if (userObj.trackertimestamp)
			{
				inputtrackertimestamp = userObj.trackertimestamp;
			}

			//userObj.lastinvited = inputtimestamp;
			userObj.lastinvited = date.getTime();
			
			if (inputpid)
			{
				var doespidexist = false;
				for (i=0; i < userObj.surveys.length; i++) {
					if (userObj.surveys[i] && userObj.surveys[i].toLowerCase() == inputpid.toLowerCase()) {
						doespidexist = true;
					}
				}
				if (doespidexist == false){
					if (userObj.surveys.length) {
						// if there are more than maxNumberOfPids elements on the array, only the last maxNumberOfPids-1 will be kept
						// and the new element will be added to the end, thus maintaining maxNumberOfPids elements in the array
						if (userObj.surveys.length < this.maxNumberOfPids) {
							userObj.surveys.push(inputpid);
						} else {
							userObj.surveys.splice(0,1);
							userObj.surveys.push(inputpid);
						}
					} else {
						userObj.surveys.push(inputpid);
					}
				}
				//remove nulls
				for (i=0; i < userObj.surveys.length; i++) {
					if (userObj.surveys[i] == null) {
						userObj.surveys.splice(i,1);
					}
				}
			}
			if (inputstate)
			{
				userObj.state.name = inputstate;
				userObj.state.url = inputurl;
				userObj.state.timestamp = inputtimestamp;
				userObj.graceperiod = inputgraceperiod;
				userObj.trackertimestamp = inputtrackertimestamp;
			}
			
			var cookieString = COMSCORE.SiteRecruit.Utils.JSONSerialize(userObj);
			//this.removeCookie(inputcookiename, { path: params.cookieoptions.path, domain: params.cookieoptions.domain });
			this.createCookie(inputcookiename,cookieString,params.cookieoptions);
			
			return userObj;
	},
	
	getUserObj: function(params) {
		
		var inputcookiename = this.getCookieName();
		if (params.cookiename){
			 inputcookiename = params.cookiename;
		}
		
		var uservalue=this.getCookieValue(inputcookiename);
		
		if (uservalue && uservalue!=""){
			var userObj = COMSCORE.SiteRecruit.Utils.JSONDeserialize(uservalue);
			//SR4.5 cookies do not store user objects, use this to overwrite
			//For future dev, we probably want to increment this version number if we want
			//to prevent scripts of different version from accessing certain cookies
			if (userObj && userObj.version && !isNaN(userObj.version) && userObj.version >= 4.6)
			{
			    return userObj;
			}
			else 
			{
				
			}
		}
		
		return null;
	}
	
};
	
	COMSCORE.SiteRecruit.DDKeepAlive = ( function() {
		// private methods and properties
		var _interval = 1000, _pageId = Math.random(), _timeoutId;
	
		// shorthand
		var _sr = COMSCORE.SiteRecruit;
		var _utils = _sr.Utils;
		
		return {
			start: function() {
				var that = this;
				
				_timeoutId = setInterval(function() {
					if (_sr.Broker.isDDInProgress() && that.isTrackerPageOpen()) {
						that.setDDTrackerCookie();
			        }
			        else if (!that.isTrackerPageOpen()){
						that.handleClosedTrackerPage();
			        }
					else {
						
						that.stop();
					}
				}, _interval);
			},
			
			stop: function() {
				clearInterval(_timeoutId);
				
			},
			
			isTrackerPageOpen: function() {
			
				//see if the tracker page has been closed while DD has been in progress
				var params = {};
				params.cookiename = COMSCORE.SiteRecruit.Broker.config.cookie.name;
				var userObj = _utils.UserPersistence.getUserObj(params);
				var now = (new Date()).getTime();
				var ret = true;
				var withinGracePeriod = false;
				var gracePeriod;
				
				if (userObj && userObj.state && userObj.state.name == _sr.CONSTANTS.STATE_NAME.DDINPROGRESS && userObj.state.timestamp && userObj.trackertimestamp) {
					//(MPA) As a fix to the DDInProgress issue, now gracePeriod is compared to the trackerTimestamp instead of state.timestamp
					//var timeDiff = now - userObj.state.timestamp;
					
					var timeDiff = now - userObj.trackertimestamp;
					var timeDiffSeconds = timeDiff/1000;
					if (COMSCORE.SiteRecruit.Builder && COMSCORE.SiteRecruit.Builder.invitation && COMSCORE.SiteRecruit.Builder.invitation.config)
					{
						gracePeriod = COMSCORE.SiteRecruit.Builder.invitation.config.trackerGracePeriod;
					}
					else if (userObj.gracePeriod) {
						gracePeriod = userObj.gracePeriod;
					}
					
					if (gracePeriod) {
						
						gracePeriod = parseInt(gracePeriod);
						
						//check if it has been more than 2 times the grace period
						//if the update time is more than the grace period, the tracker was probably closed which 
						//is why its still in a DDINPROGRESS but past the grace period
						var timeWindow = 2 * gracePeriod * 1000;
						withinGracePeriod = (timeDiff < timeWindow);
						if (!withinGracePeriod) {
							
							ret = false;
						}
					}
				}
				return ret;
				
			},
			
			handleClosedTrackerPage: function() {
				
				var params = {};
				var c = _sr.Broker.config.cookie;
				params.cookiename = c.name;
				params.statename = _sr.CONSTANTS.STATE_NAME.IDLE;
				params.cookieoptions = { path: c.path, domain: c.domain };
				params.url = escape(_utils.location);
				params.timestamp = (new Date()).getTime();
				_utils.UserPersistence.setUserObj(params);
				this.stop();
			},
			
			setDDTrackerCookie: function() {
			
				var c = _sr.Broker.config.cookie;		
				var params = {};
				params.cookiename = c.name;
				var userObj = _utils.UserPersistence.getUserObj(params);
				
				var params = {};
				params.cookiename = c.name;
				params.cookieoptions = { path: c.path, domain: c.domain };
				params.url = escape(_utils.location);
				params.statename = _sr.CONSTANTS.STATE_NAME.DDINPROGRESS;
				params.timestamp = (new Date()).getTime();
				
				if (COMSCORE.SiteRecruit.Builder && COMSCORE.SiteRecruit.Builder.invitation && COMSCORE.SiteRecruit.Builder.invitation.config){
					//adding pid here so it gets passed to confirmit
					params.pid = COMSCORE.SiteRecruit.Builder.invitation.config.projectId
					params.graceperiod = COMSCORE.SiteRecruit.Builder.invitation.config.trackerGracePeriod;
				}
				else if (userObj && userObj.gracePeriod)
				{
					//set gracePeriod from previous cookie value
					params.graceperiod = userObj.graceperiod;
				}

				_utils.UserPersistence.setUserObj(params);	
			}
		};
	} )();
	
	COMSCORE.SiteRecruit.PagemapFinder = ( function() {
		// private methods and properties
		var _totalFreq;
		// shorthand
		var _sr = COMSCORE.SiteRecruit;
		var _utils = _sr.Utils;
		
		return {
			
			getTotalFreq: function() {
				return _totalFreq;
			},
			
			find: function(mappings) {
				var currentPriority = 0, currentMatch;
				var m = mappings;
				//cjones 11/1/07
				var matchList = [];
				var halt = false;
				_totalFreq = 0;
				// Iterate over each URL.
				for (var i = 0; m && i < m.length; i++) {
					var matchPrereqs = false;
							
					var pm = m[i];
					 if (pm) {
						// Do the reg exp match.
						var r = new RegExp(pm.m, 'i');			
						if (_utils.location.search(r) != -1) {	// does current url match regex?
							
							// Now check the prereqs.
							var pr = m[i].prereqs;
							
							matchPrereqs = true;
							if (pr) {	
								

								if (!this.isMatchContent(pr.content)) {
									
									matchPrereqs = false;
								}
									
								if (!this.isMatchCookie(pr.cookie)) {
									
									matchPrereqs = false;
								}
								
								if (!this.isMatchLanguage(pr.language)) {
									
									matchPrereqs = false;
								}
								
								
								// Third-party cookie reading pushed to the end of the sprint. Disabled till then
								//if (!this.isMatchExternalCookie(pr.externalDomain)) {
									
								//	matchPrereqs = false;
								//}
								
							}
						}		
						//cjones push match onto array
						if (matchPrereqs) {
						    if (pm.halt) {
								
								halt = true;
								break;
							}
							else
							{
							    matchList.push(pm);
							    
							    //setting totalFreq to last matched as a precaution, freq should be adjusted when match is selected
								_totalFreq = pm.f; 
							}
						}				
					}
				}
				if (halt == true) {
					matchList = null;
					_totalFreq = 0;
					return null;
				}
				
				
				return this.choosePriority(matchList);
			},
		
			choosePriority: function(matchList) {
				var prevMatch = null;
				for (var i = 0; i < matchList.length; i++) {
					if (prevMatch == null) {
						prevMatch = matchList[i];
						_totalFreq = matchList[i].f; 
					}
					else {
						if (prevMatch.p < matchList[i].p) {
							prevMatch = matchList[i];
							//set the private class variable so getTotalFreq returns the right value
							_totalFreq = matchList[i].f; 
						}
						
					}
				}
				return prevMatch;
			},
			
			isMatchContent: function(content) {
				var isMatch = true, i = 0;
				
				while (isMatch && i < content.length) {
					
					var matchContent = false;
	                var matchAttribute = false;
	                								
					var c = content[i];
					
					if (c.element) {
	                    var elements = document.getElementsByTagName(c.element);
	                    var flag = true;
	                    
						for (var k = 0; k < elements.length; k++) {
							//var val = c.elementValue;
							var val = new RegExp(c.elementValue);
	                        
							if (val) {
	                            //if (elements[k].innerHTML.search(val) != -1) {
	                            if (val.test(elements[k].innerHTML)) {
									if (flag) {
										
										flag = false;
									}
	                                matchContent = true;
	                            }
	                        }
	                        else {
	                            matchContent = true;
	                        }
	                        
							if (c.attrib && c.attrib.length) {
								var a = elements[k].attributes.getNamedItem(c.attrib);
								var val2 = new RegExp(c.attribValue);
	                            if (a) {
									if (c.attribValue && c.attribValue.length) {
										if (val2.test(a.value)) {
										//if (a.value.search(c.attribValue) != -1) {
											matchAttribute = true;
	                                    }
	                                }
									else {
										matchAttribute = true;
	                                }
	                            }
	                        }
	                        else {
								matchAttribute = true;
							}
						}
					}
	                
	                if (!matchContent || !matchAttribute) {
	                    isMatch = false;
	                }
			i++;
				}
				
				return isMatch;		
			},
			
			isMatchCookie: function(cookies) {
				var isMatch = true, i = 0;
				
				while (isMatch && i < cookies.length) {
					
					// This matches on cookies specified in the console-> Page Mappings -> Edit prereqs
					
					var c = cookies[i], val = _utils.UserPersistence.getCookieValue(c.name);
							
					if (val && val !== null) {
					
						//Treat c.value as RegExp
						var regExp = new RegExp(c.value);
						
							

						isMatch = regExp.test(val);
						i++;
					}
					else {
						return false;
					}
				}
				
				return isMatch;
			},
			
			isMatchLanguage: function(lang) {
				var n = navigator.language || navigator.userLanguage;
				n = n.toLowerCase();
				if  (!lang) {
					return true;
				}
				var regExp = new RegExp(lang);
				//if (n.indexOf(lang) != -1) {
				if (regExp.test(n)) {
					
	                return true;
	            }
				
				
				return false;
			},
			
			verifyExternalCookie: function(cookie) {
				COMSCORE.SiteRecruit.Broker.extCookie = cookie;
			},
			
			readExternalCookie: function(externalDomainPrereq) {
				// Make a call to the rc.pli file
				var domain = externalDomainPrereq[0].domain;
				var cookieName = externalDomainPrereq[0].name;
				var func = "COMSCORE.SiteRecruit.PagemapFinder.verifyExternalCookie"
				var rUrl = domain + "?n=" + cookieName + "&func=" + func + "&";
				_utils.loadScript(rUrl, false);			
			},
			
			isMatchExternalCookie: function(externalDomainPrereq) {
				//COMSCORE.SiteRecruit.PagemapFinder.readExternalCookie(externalDomainPrereq);
			
				var domain = externalDomainPrereq[0].domain;
				var cookieName = externalDomainPrereq[0].name;
				var func = "COMSCORE.SiteRecruit.PagemapFinder.verifyExternalCookie"
				
				var rUrl = domain + "?n=" + cookieName + "&func=" + func + "&";
				var extScript;
				//_utils.loadScript(rUrl, false);
				
				var scripts = document.getElementsByTagName( 'script' );
				for (var i = 0; i < scripts.length; i++) {
					if (scripts[i].src.search(domain) != -1) {
						extScript = scripts[i];
					}
				}
				
				if (COMSCORE.SiteRecruit.Broker.extCookie && COMSCORE.SiteRecruit.Broker.extCookie != "") {
					
					return true;
				} 
				else {
					
					return false;
				}
			}
		};
	} )();
	
	COMSCORE.SiteRecruit.Broker = ( function() {
		// private method and properties
		
		// for short hand
		var _sr = COMSCORE.SiteRecruit;
		var _utils = _sr.Utils;
		var _extCookie = "!";
	
		// public methods and properties
		return {
			/**
			Events: {
				
				 * @param {Object} utils - a reference to COMSCORE.SiteRecruit.Utils class for quick access
				 * @param {Object} options - contains the bool: IsLucky
				 
				beforeRecruit: function() {}
			},
			*/
			
			init: function() {
				
				
				_sr.browser = _utils.getBrowser();
				_sr.executingPath = _utils.getExecutingPath("broker.js");
			
				if (_sr.browser.ie || _sr.browser.mozilla) {
					_utils.loadScript(_sr.executingPath + _sr.configUrl, true);
				}
				else {
					
					return;
				}
			},
				
			start: function() {
				if (/iphone|ipad|ipod|android|opera mini|blackberry|windows (phone|ce)|iemobile|htc|nokia/i.test(navigator.userAgent)) {
					// HALT RECRUITMENT FOR MOBILE DEVICES  			
				}else{
					this.init();		
				}		
			},
			readVoicefiveCookies : function() {
				
				//Add call to rcAll.pli (reads All VoiceFive.com cookies) and then calls the checkOptOutCookie function
				var s = document.createElement("script");
				var callback = "func=COMSCORE.SiteRecruit.Broker.checkOptOutCookie";
				// TODO: re-check this out to make work with a dynamic domain
				//s.src = "http://ar.voicefive.com/b/rcAll.pli?" +  callback ;
				s.src = "https://ar.voicefive.com/b/rcAll.pli?" +  callback ;
				
				 
				document.body.appendChild(s);
			},
		
			checkOptOutCookie : function(voicefiveCookieObject) {
				if(this.config.thirdPartyOptOutCookie1 && this.config.thirdPartyOptOutCookie2){
				
					if (voicefiveCookieObject[this.config.thirdPartyOptOutCookie1.name] != undefined || voicefiveCookieObject[this.config.thirdPartyOptOutCookie2.name] != undefined) {
					COMSCORE.SiteRecruit.Broker.optoutCookiePresent = true;
					
					return;
					}
					else {
						COMSCORE.SiteRecruit.Broker.optoutCookiePresent = false;
						
						COMSCORE.SiteRecruit.Broker.run();
					}
				}else{
					COMSCORE.SiteRecruit.Broker.optoutCookiePresent = false;
					COMSCORE.SiteRecruit.Broker.run();
				}
				
				

			},
			
			run: function() {
				
				
				//initialize IE user data persistence if and only if 
				//this option has been enabled and the browser is ie
				
				this.config.Events.beforeRecruit();
				
				if (this.config.objStoreElemName) {
					if (_sr.browser.ie) {
						COMSCORE.SiteRecruit.Utils.UserPersistence.initialize();
					}
					else {
						
						return;
					}
				}
				
				// verify versions match
				if (_sr.version !== this.config.version) {
					
					return;
				}
				
				//verify test mode
				var testModeConfig = this.config.testMode;
				var testModeURL;
				var testMode;
				
				testModeURL = (_utils.UserPersistence.getCookieValue("tstMode") == 1)?true:false;
				
				testMode = (testModeConfig || testModeURL);
				
				if (this.isDDInProgress()) {
					this.processDDInProgress();
				}
				

				if(COMSCORE.SiteRecruit.Broker.config.thirdPartyOptOutCookieEnabled == true){
					if(typeof(COMSCORE.SiteRecruit.Broker.optoutCookiePresent) == "undefined" ){
						this.readVoicefiveCookies();
						return;
					}
				}

				
				if (!testMode || this.isDDInProgress()) {
					// if any site recruit exists, stop executing
					//if (_utils.UserPersistence.get(this.config.cookie.name) !== false) {
					//	
					//	return;
					//}
					
					// this is being changed to match the new logic
					// OLD: if there is a cookie then stop
					// NEW: if there is a cookie, check the timestamp ( make sure it is more than 90 days), also make sure to exit if dd
					
					var params = {};
					params.cookiename = this.config.cookie.name;
					var userObj = _utils.UserPersistence.getUserObj(params);
					var date = new Date();
					var durationdays = this.config.cookie.duration;
					var durationtimestamp = date.getTime() - ( durationdays * 24 * 60 * 60 * 1000);
					
					if (userObj) {
						if (userObj.lastinvited > durationtimestamp) {
								

								return;
							//}
						}
					}
					
				}	
				
				if (this.findPageMapping())
				{
					if (testMode) {
						
						if (this.pagemap) {
							this.loadBuilder();
						}
						return;
					}
					
					// roll the dice
					var r = _utils.getRandom();
						
					if (r <= _sr.PagemapFinder.getTotalFreq()) {
						
						//cjones
						if (this.pagemap) {
							this.loadBuilder();
						}	
					}
					else {
						
						return;
					}
				}
				else {
					
					return;
				}
			},		
			
			isDDInProgress: function() {
				//var c = _utils.UserPersistence.get(COMSCORE.SiteRecruit.Broker.config.cookie.name);
				//return (c && c.indexOf(_sr.CONSTANTS.COOKIE_TYPE.DD_IN_PROGRESS) === 0);
				
				var ddinprogress = false;
				var params = {};
				params.cookiename = COMSCORE.SiteRecruit.Broker.config.cookie.name;
				var userObj = _utils.UserPersistence.getUserObj(params);
				
				if (userObj) {
					if (userObj.state.name == _sr.CONSTANTS.STATE_NAME.DDINPROGRESS) {
						ddinprogress = true
						
					}
				}

				return ddinprogress;
			},
			
			processDDInProgress: function() {
				//Ensure this function is only called when state name is DDINPROGRESS
				// launch dd keep alive
				
				_sr.DDKeepAlive.start();
			},
			
			findPageMapping: function() {
				this.pagemap = _sr.PagemapFinder.find(this.config.mapping);	
				return this.pagemap;
			},
			
			loadBuilder: function() {
				// prefix pageconfig url if it's supplied
				var url = _sr.executingPath + _sr.builderUrl;
				/*
				var p = this.config.prefixUrl;
						
				if (p) {
					url = p + url;
				}
				*/
				_utils.loadScript(url);
				
			}
		};
	} )();
	
	COMSCORE.isDDInProgress = COMSCORE.SiteRecruit.Broker.isDDInProgress;
	
	COMSCORE.SiteRecruit.OnReady = ( function() {
		// for short hand
		var _sr = COMSCORE.SiteRecruit;
		var _utils = _sr.Utils;
		
		// public methods and properties
		return {
			onload : function() {
				if (_sr.OnReady.done) { return; }
				_sr.OnReady.done = true;
				_sr.Broker.start(); //initialize the broker once the DOM is ready
				//clean up
				//safari
				if(_sr.OnReady.timer){
					
					clearInterval(_sr.OnReady.timer);
				}
				//mozilla opera
				 if(document.addEventListener) {
					 
					document.removeEventListener("DOMContentLoaded", _sr.OnReady.onload, false);
				}
				//ie
				 if(window.ActiveXObject){
					 
					/*
					var defer = document.getElementById("sr__ie_onload");
					if(defer){
						defer.onreadystatechange = null;
						defer.parentNode.removeChild(defer);
					}
					*/
				}
			},
			listen : function() {
				//safari
				if (/WebKit|khtml/i.test(navigator.userAgent)) {
					_sr.OnReady.timer = setInterval(function() {
						if (/loaded|complete/.test(document.readyState)) {
							clearInterval(_sr.OnReady.timer);
							delete _sr.OnReady.timer;
							_sr.OnReady.onload();
						}}, 10);
				}
				//mozilla opera 
				else if (document.addEventListener) {
					document.addEventListener('DOMContentLoaded', _sr.OnReady.onload, false);
				}
				//ie
				else if (window.ActiveXObject) {
					//_sr.OnReady.iew32 = true;
					//document.write('<script id="sr__ie_onload" defer src="' + ((location.protocol == 'https:') ? '//0' : 'javascript:void(0)') + '"><\/script>');
					//document.getElementById('sr__ie_onload').onreadystatechange = function(){if (this.readyState == 'complete') { _sr.OnReady.onload(); }};
					COMSCORE.SiteRecruit.OnReady.waitForLoad = setInterval(function() {
				                try {
				                    // throws errors until after ondocummentready
				                    document.documentElement.doScroll('left');
								} catch (ex) {
									return;
				                }
				                COMSCORE.SiteRecruit.OnReady.waitForLoad = clearInterval(COMSCORE.SiteRecruit.OnReady.waitForLoad);
								COMSCORE.SiteRecruit.OnReady.onload();
				            }, 1000);
				}
				//default ??
				else  {
					if(window.addEventListener) {
						window.addEventListener('load', _sr.OnReady.onload, false);
					} else if (window.attachEvent) {
						return window.attachEvent('onload', _sr.OnReady.onload);
					}
				}
			},
			f:[],done:false,timer:null
		};
	})();
	
	COMSCORE.SiteRecruit.OnReady.listen();
}// namespace (if statement at the top)