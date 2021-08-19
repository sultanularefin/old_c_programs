/*
Copyright (c) 2013, comScore Inc. All rights reserved.
version: 5.0.3
*/
COMSCORE.SiteRecruit.Builder.config = {
	version: "5.0.3",
	
	// invitations' settings
	invitation: [
							
											{ 	methodology: 2,
					projectId: 'p77596864',
					weight: 73,
					isRapidCookie: false,
					acceptUrl: 'http://survey2.surveysite.com/wix/p77596864.aspx ',
					secureUrl: '',
					acceptParams: {
						raw: '',
						siteCode: '1207',
												cookie: [
													],
												otherVariables: [
													]
					},
					viewUrl: 'http://web.survey-poll.com/tc/CreateLog.aspx',
					viewParams: 'log=comscore/view/p77596864-view.log',
					content: '<div style="width:366px; border: 1px solid #3b3b3b;background-color:#FFF;"><div style="position:relative; top:12px; left:56px"> 	<div style="height:44px;font-family:\'Segoe UI Light\'; font-size:24px; color:#000;"> 		Please help us improve 		<div style="position:relative; top: -17pt; left:250px; width: 26; height: 26;"><a href="javascript:void(0);" onclick="@declineHandler"><img src="close_v3.gif" border="0"/></a></div> 	</div> 	<div style="font-family:\'Segoe UI\'; font-size:12px; color:#000; width:250px;line-height:14px;"> 		Microsoft is conducting an online survey to understand your opinion of the MSDN Web site.  If you choose to participate, the online survey will be presented to you when you leave the MSDN Web site. <br /><br />Would you like to participate?     	</div> 	 	<div style="width:300px;height:38px;margin-top:28px;"> 		 		<div style="width:91px;" > 			       <input name="button" type="button" value=" I want to " style="border-style:none; background-color:#000000; font-family:\'Segoe UI\'; font-size:12px; color:#FFF; height:34px;width:91px;" onclick="@acceptHandler;"/>     </div> 	       <div style="position:relative; top: -34px; left:147px; width:91px;height:34px;">     	<input name="button" type="button" value=" No thanks " style="border-style:none; background-color:#000000; font-family:\'Segoe UI\'; font-size:12px; color:#FFF; height:34px;width:91px;" onclick="@declineHandler;"/>	     </div> 	  		   </div> 	     <div style="margin-top:10px;"> 	  	   	<img src="msdn-logo-stripe2.gif" style="display:inline">  	  	     <div style="position:relative; top: -20px; left:147px;width:150px;"><a href="http://privacy.microsoft.com/en-us/default.mspx" style="font-family:\'Segoe UI\'; font-size:10px; color:#0072bc; text-decoration:none;" target="_blank">Privacy Statement</a></div> 	     </div><br />  </div></div>',
					height: 300,
					width: 390,
					revealDelay: 1000,
					horizontalAlignment: 1,
					verticalAlignment: 1,
					horizontalMargin: 0,
					verticalMargin: 0,
					isHideBlockingElements: false,
					isAutoCentering: true,
					url: 'SiteRecruit_Tracker.htm',
					trackerGracePeriod: 5
					,usesSilverlight: false
					
					//silverlight config
										
											,trackerWindow: {
							width: 400,
							height: 270,
							orientation: 1,
							offsetX: 0,
							offsetY: 0,
							hideToolBars: true,
							trackerPageConfigUrl: 'trackerConfig_SC-MSDN-p77596864.js'
							// future feature: 
							//features: "location=0,menubar=0,resizable=1,scrollbars=1,toolbar=0"
						}
																				,Events: {
						beforeRender: function() {
														
													}
						,beforeDestroy: function() {
														
													}
						,beforeAccept: function() {
														COMSCORE.SiteRecruit.Builder.invitation.config.acceptParams.raw = _raw_params;
													}
						,beforeDecline: function() {
														
													}
						,beforeRenderUpdate: function() {
														
													}
						,afterRender: function() {
														
													}
					}
				}
								
											,
								{ 	methodology: 2,
					projectId: 'p77737117',
					weight: 27,
					isRapidCookie: false,
					acceptUrl: 'http://survey2.surveysite.com/wix/p77737117.aspx',
					secureUrl: '',
					acceptParams: {
						raw: 'l=9',
						siteCode: '1207',
												cookie: [
													],
												otherVariables: [
													]
					},
					viewUrl: 'http://web.survey-poll.com/tc/CreateLog.aspx',
					viewParams: 'log=comscore/view/p77737117-view.log',
					content: '<table width="360" cellpadding="3" cellspacing="0" style="background:#FFFFFF; margin:0;border:1px solid #cccccc;"> 	<tr><td style="border:0; padding:0; margin:0" >  		<table width="100%" cellpadding="1" cellspacing="0" border="0" style="margin:0; padding:0"> 			<tr><td style="border:0; padding:0; margin:0" >  				<table width="100%" cellpadding="0" cellspacing="0" border="0" style="background:#FFFFFF; margin:0"> 					<tr valign="top"><td style="border:0; padding:0; margin:0" >  						<img src="msdn-logo-stripe.gif" style="display:inline"><a href="javascript:void(0);" onclick="@declineHandler"><img border="0" src="msdn-close.gif" style="display:inline" /></a><br />  						<img src="top-stripe.gif" style="display:inline" />  						<table width="100%" cellpadding="5" style="margin:0"><tr><td style="padding:3px;border:0;">   							 							<div style="font-family: Verdana, Arial, Helvetica, sans-serif;	font-size: 11px; color: #000000; margin: 0 0 15px 0; padding:3; text-align:left">Microsoft is conducting an online survey to understand your opinion of the MSDN Web site.  If you choose to participate, the online survey will be presented to you when you leave the MSDN Web site. <br /><br /> Would you like to participate?    </div>   							 							<div align="center" style="margin: 0; padding: 0">  								<input style="margin: 0; padding: 0" type="button" value="  Yes  " onclick="@acceptHandler" />&nbsp;&nbsp;  								<input style="margin: 0; padding: 0"  type="button" value=" No " onclick="@declineHandler" />  							</div>   							 							<div style="font-family: Verdana, Arial, Helvetica, sans-serif;	font-size: 11px; color: #000000; margin: 15px 0 2px 0; text-align:left"><a style="color:#0000EE; text-decoration: underline; " href="http://privacy.microsoft.com/en-us/default.mspx" target="_blank">Privacy Statement</a></div>   							 						</td></tr></table>  						<img src="bottom-stripe.gif" style="display:inline" /></td></tr></table>  				</td></tr></table> 		</td></tr></table> </td></tr></table>',
					height: 210,
					width: 390,
					revealDelay: 1000,
					horizontalAlignment: 1,
					verticalAlignment: 1,
					horizontalMargin: 0,
					verticalMargin: 0,
					isHideBlockingElements: false,
					isAutoCentering: true,
					url: 'SiteRecruit_Tracker.htm',
					trackerGracePeriod: 5
					,usesSilverlight: false
					
					//silverlight config
										
											,trackerWindow: {
							width: 400,
							height: 270,
							orientation: 1,
							offsetX: 0,
							offsetY: 0,
							hideToolBars: true,
							trackerPageConfigUrl: 'trackerConfig_MSDN-p77737117.js'
							// future feature: 
							//features: "location=0,menubar=0,resizable=1,scrollbars=1,toolbar=0"
						}
																				,Events: {
						beforeRender: function() {
														
													}
						,beforeDestroy: function() {
														
													}
						,beforeAccept: function() {
														COMSCORE.SiteRecruit.Builder.invitation.config.acceptParams.raw = _raw_params;
													}
						,beforeDecline: function() {
														
													}
						,beforeRenderUpdate: function() {
														
													}
						,afterRender: function() {
														
													}
					}
				}
						]
};
COMSCORE.SiteRecruit.Builder.run();
