/*
Copyright (c) 2012, comScore Inc. All rights reserved.
version: 5.0.3
*/
function _set_SessionCookie(n, f){
  var c = n+'=' + f  	    	
  				+ '; path=/'
   			 	+ '; domain=.microsoft.com';
	document.cookie = c;	
}

var allLinks = document.getElementsByTagName("a");
function  checkLink(){
 for (var i = 0, n = allLinks.length; i < n; i++) {
 	if(/https:\/\/login\.live\.com\/login/i.test(allLinks[i].href)){ 
		if(allLinks[i].addEventListener){
			allLinks[i].addEventListener('click',function(event){
				_set_SessionCookie("graceIncr", 1);
						},false);
		}else{
			hrefURL = allLinks[i].href;
			allLinks[i].attachEvent('onclick',function(){ 
				_set_SessionCookie("graceIncr", 1);
							});
		}
 	}
 }
        }
 setTimeout("checkLink();", 3000);
 _set_SessionCookie("graceIncr", 0);

COMSCORE.SiteRecruit.Broker.config = {
	version: "5.0.3",
	//TODO:Karl extend cookie enhancements to ie userdata
		testMode: false,
	
	// cookie settings
	cookie:{
		name: 'msresearch',
		path: '/',
		domain:  '.microsoft.com' ,
		duration: 90,
		rapidDuration: 0,
		expireDate: ''
	},
	thirdPartyOptOutCookieEnabled : false,
	
	// optional prefix for pagemapping's pageconfig file
	prefixUrl: "",
	
	//events
	Events: {
		beforeRecruit: function() {
					}
	},
	
		mapping:[
	// m=regex match, c=page config file (prefixed with configUrl), f=frequency
	{m: 'support\\.microsoft\\.com/search/default\\.aspx', c: 'inv_c_SupportSearch-p176726013.js', f: 0, p: 0, halt:true 	
		,prereqs:{
			content: [
								  							]
			,cookie: [
								  										{
						'name':'gssLANG'
						,'value':'en-(us|US)'					}
									  							]									
			,externalDomain: [
																]
		}	
	}
]
};
COMSCORE.SiteRecruit.Broker.run();