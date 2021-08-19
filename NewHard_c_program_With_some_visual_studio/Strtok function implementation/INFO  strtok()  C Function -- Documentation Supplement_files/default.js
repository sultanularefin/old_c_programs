function srcEl(n){return n.srcElement?n.srcElement:n.target?n.target:n}function parseBoolean(n){switch(n.toLowerCase()){case"true":case"yes":case"1":return!0;case"false":case"no":case"0":case null:return!1;default:return Boolean(n)}}function OutputEncoder_EncodeUrl(n){var t,i,r;if(typeof n=="undefined")return"";for(n=n.toString(),i="",r=0;r<n.length;r++)t=n.charCodeAt(r),i=t>96&&t<123||t>64&&t<91||t>47&&t<58||t==46||t==45||t==95?i+String.fromCharCode(t):t>127?i+"%u"+OutputEncoder_TwoByteHex(t):i+"%"+OutputEncoder_SingleByteHex(t);return i}function OutputEncoder_SingleByteHex(n){for(var t=n.toString(16),i=t.length;i<2;i++)t="0"+t;return t}function OutputEncoder_TwoByteHex(n){for(var t=n.toString(16),i=t.length;i<4;i++)t="0"+t;return t}function MS_QueryString(){var i=document.location.search.toString(),f,r,n,t,u;for(i.length>0&&(i=i.substring(1)),f=i.split("&"),r=0;r<f.length;r++){n=f[r].split("=");if(n.length!=2)continue;if(n[1]=="")continue;try{t=decodeURIComponent(n[0]).toLowerCase(),u=decodeURIComponent(n[1])}catch(e){t=unescape(n[0]).toLowerCase(),u=unescape(n[1])}this[t]?this[t]+=","+u:this[t]=u}}function GetModifiedQueryString(n,t){var r={},u,i;for(i in queryString)r[i]=queryString[i];r[n]=t,u="";for(i in r)u+=OutputEncoder_EncodeUrl(i)+"="+OutputEncoder_EncodeUrl(r[i])+"&";return"?"+u}function UnicodeFixup(n){for(var r=new String,i="",t=-1,u=n.length,r="",t=0;t<u;t++)i=n.substring(t,t+1),i=="%"?(r+=i,t++,i=n.substring(t,t+1),i!="u"&&parseInt("0x"+n.substring(t,t+2))>128&&(r+="u00")):i=="+"&&(i="%2B"),r+=i;return r}function ForeignLink_Hookup(n){var t,r,u,f,i;for(typeof n=="undefined"&&(n="true"),t=null,i=0;i<$("a").length;i++)t=$("a").get(i),(t.protocol=="http:"||t.protocol=="https:")&&(!n&&(t.href.indexOf(document.domain)>-1||t.href.substring(0,1)=="/")&&t.href.toLowerCase().indexOf("fr=1")<0&&(r=t.href.split("#"),u="",r.length>1&&(u="#"+r[1]),t.href=t.href.indexOf("?")>-1?r[0]+"&FR=1"+u:r[0]+"?FR=1"+u),g_reSupportedHostnames.exec(t.hostname)&&(n||t.href.indexOf(document.domain)>=0)||(t.target="_blank"));if(!n)if(document.getElementsByName)for(f=null,i=0;i<$("form").length;i++)eCurrentForm=$("form").get(i),(eCurrentForm.action.indexOf(document.domain)>-1||eCurrentForm.action.substring(0,1)=="/")&&(eCurrentForm.FR||$(eCurrentForm).append('<input id="FR" name="FR" value="1" type="hidden" />'))}function MS_PageToolsData(){function n(){for(var n=0;;){if(!eval("window.SaveToFavoritesData"+n))return"SaveToFavoritesData"+n;n++}}this.closeMsg="Close",this.noCookieUrl="/gp/nocookies/",this.id=n(),window[this.id]=this,this.PrintPage=function(){StatsDotNet.eventCollectionId=SetLogCollectionBit(StatsDotNet.eventCollectionId,2);try{window.print()}catch(n){}return!1},this.EmailPage=function(){return StatsDotNet.eventCollectionId=SetLogCollectionBit(StatsDotNet.eventCollectionId,3),!0}}function MS_StatsDotNet(){var t,n;this.startDate=new Date,this.disabled=!0,this.host="/LTS/",this.scrollUsed=!1,this.reCleanId=/[^0-9]*/i,this.eventCollectionId=0,this.OptionCollectionId=0,this.ContentProperties="",this.refUrl="",this.contentType="",this.contentLn="",this.contentId="",this.ContentCulture="",this.exitContainerId="",this.exitLinkId="",this.platform="",this.activeDwellTime=0,this.activeStartTime=this.startDate,this.lightboxCloseTime=null,this.suppressBlur=!1,this.activeElement=null,this.timeoutID=-1,this.isIE=!1,this.logExternalUrls=!1,t=fetchcookieval("exitinfo"),t&&(n=t.split("|"),n.length==6&&(this.rctype=n[0],this.rclcid=n[1],this.rcid=n[2],this.rcculture=n[3],this.rexcid=n[4],this.rexlid=n[5])),document.referrer&&document.referrer!=""&&(this.refUrl=document.referrer.toString()),this.eventSeqNo=0,this.targetUrl="",this.sessionId="",this.onUnloadTimeout=null,this.ltsIdleTimeout=null,this.externalUrls=[],this.CleanId=function(n){try{return n.replace(this.reCleanId,"")}catch(t){}return""},this.AddActiveTime=function(n){if(StatsDotNet.activeStartTime==null||arguments.length==1&&StatsDotNet.activeElement!=document.activeElement&&StatsDotNet.isIE){StatsDotNet.activeElement=document.activeElement;return}if(StatsDotNet.suppressBlur)return;StatsDotNet.activeDwellTime+=n.getTime()-StatsDotNet.activeStartTime.getTime(),StatsDotNet.lightboxCloseTime!=null&&(StatsDotNet.flexValue6+=n.getTime()-StatsDotNet.activeStartTime.getTime()),StatsDotNet.activeStartTime=null},this.CheckActivity=function(){StatsDotNet.activeStartTime!=null&&StatsDotNet.AddActiveTime(new Date)},this.ResetDwellTime=function(){StatsDotNet.timeoutID!=-1&&clearTimeout(StatsDotNet.timeoutID),StatsDotNet.timeoutID=setTimeout(StatsDotNet.CheckActivity,StatsDotNet.ltsIdleTimeout),StatsDotNet.activeStartTime==null&&(StatsDotNet.activeStartTime=new Date)},this.FocusHandler=function(){StatsDotNet.ResetDwellTime(),StatsDotNet.activeStartTime!=null||(document.activeElement==null||StatsDotNet.activeElement!=document.activeElement)&&StatsDotNet.isIE||(StatsDotNet.activeStartTime=new Date)},this.HookLoadEvents=function(){StatsDotNet.logExternalUrls=this.ssId&&this.ssId=="1",StatsDotNet.isIE=navigator.appName=="Microsoft Internet Explorer",StatsDotNet.activeElement=document.activeElement,StatsDotNet.isIE?(document.onfocusin=StatsDotNet.FocusHandler,document.onfocusout=function(){StatsDotNet.AddActiveTime(new Date)}):($(window).focus(StatsDotNet.FocusHandler),$(window).blur(function(){StatsDotNet.AddActiveTime(new Date)})),StatsDotNet.timeoutID=setTimeout(StatsDotNet.CheckActivity,StatsDotNet.ltsIdleTimeout),$(document.body).mousemove(StatsDotNet.ResetDwellTime),$(document.body).click(StatsDotNet.ResetDwellTime),$(document.body).keypress(StatsDotNet.ResetDwellTime),$(window).scroll(StatsDotNet.ResetDwellTime)},this.LogPageOnLoad=function(){this.enableCollTierParams&&this.HookLoadEvents(),$("#acwkblink").get(0)&&(StatsDotNet.OptionCollectionId=SetLogCollectionBit(StatsDotNet.OptionCollectionId,32)),this.eventSeqNo===0&&(this.eventSeqNo=this.GetCookieIncrement()),typeof window.innerWidth=="number"?(StatsDotNet.browserWidth=window.innerWidth,StatsDotNet.browserHeight=window.innerHeight):document.documentElement&&(document.documentElement.clientWidth||document.documentElement.clientHeight)?(StatsDotNet.browserWidth=document.documentElement.clientWidth,StatsDotNet.browserHeight=document.documentElement.clientHeight):document.body&&(document.body.clientWidth||document.body.clientHeight)&&(StatsDotNet.browserWidth=document.body.clientWidth,StatsDotNet.browserHeight=document.body.clientHeight);var n=this.host+"?";this.sessionId!=""&&(n+="SessionID="+OutputEncoder_EncodeUrl(this.sessionId)+"&"),n+="SSID="+OutputEncoder_EncodeUrl(this.ssId)+"&SiteLCID="+OutputEncoder_EncodeUrl(this.siteLcId)+"&EventCollectionID="+OutputEncoder_EncodeUrl(this.eventCollectionId)+"&URL="+OutputEncoder_EncodeUrl(this.url)+"&ContentType="+OutputEncoder_EncodeUrl(this.contentType)+"&ContentLCID="+OutputEncoder_EncodeUrl(this.contentLn)+"&ContentID="+OutputEncoder_EncodeUrl(this.contentId)+"&rctype="+OutputEncoder_EncodeUrl(this.rctype)+"&rclcid="+OutputEncoder_EncodeUrl(this.rclcid)+"&rcid="+OutputEncoder_EncodeUrl(this.rcid)+"&rcculture="+OutputEncoder_EncodeUrl(this.rcculture)+"&rexcid="+OutputEncoder_EncodeUrl(this.rexcid)+"&rexlid="+OutputEncoder_EncodeUrl(this.rexlid)+"&BrowserWidth="+this.browserWidth+"&BrowserHeight="+this.browserHeight+"&BrandID="+OutputEncoder_EncodeUrl(this.siteBrandId)+"&RefURL="+OutputEncoder_EncodeUrl(this.refUrl)+"&OptionCollectionId="+OutputEncoder_EncodeUrl(this.OptionCollectionId)+"&EventSeqNo="+OutputEncoder_EncodeUrl(this.eventSeqNo)+"&SSversion="+OutputEncoder_EncodeUrl(this.SsVersion)+"&SiteCulture="+OutputEncoder_EncodeUrl(this.SiteCulture)+"&Platform="+OutputEncoder_EncodeUrl(this.platform)+"&ContentCulture="+OutputEncoder_EncodeUrl(this.ContentCulture)+"&PassportStatus="+OutputEncoder_EncodeUrl(this.PassportStatus)+"&In404Url="+OutputEncoder_EncodeUrl(this.In404Url)+"&ContentProperties="+OutputEncoder_EncodeUrl(this.ContentProperties)+"&FlexID="+OutputEncoder_EncodeUrl(this.flexId)+"&FlexValue1="+OutputEncoder_EncodeUrl(this.flexValue1)+"&FlexValue2="+OutputEncoder_EncodeUrl(this.flexValue2)+"&FlexValue3="+OutputEncoder_EncodeUrl(this.flexValue3)+"&FlexValue4="+OutputEncoder_EncodeUrl(this.flexValue4)+"&FlexValue5="+OutputEncoder_EncodeUrl(this.flexValue5),this.enableCollTierParams&&(n+="&FlexValue6="+OutputEncoder_EncodeUrl(this.flexValue6)+"&FlexValue7="+OutputEncoder_EncodeUrl(this.flexValue7)+"&FlexValue8="+OutputEncoder_EncodeUrl(this.flexValue8)+"&FlexValue9="+OutputEncoder_EncodeUrl(this.flexValue9)+"&FlexValue10="+OutputEncoder_EncodeUrl(this.flexValue10)),typeof varWedcsEnable!="undefined"&&varWedcsEnable||generateWedcsData(),$("#StatsDotNetImg").get(0).src=n},this.LogPageOnUnLoad=function(){var n,t,i,r,u,f;if(fetchcookieval("GsfxStatsLog")!="true")return;this.endDate=new Date,this.dwellTime=this.endDate.getTime()-this.startDate.getTime(),this.scrollUsed&&(StatsDotNet.eventCollectionId=SetLogCollectionBit(StatsDotNet.eventCollectionId,27)),this.eventSeqNo===0&&(this.eventSeqNo=this.GetCookieIncrement()),srch_setcookieval("exitinfo",this.contentType+"|"+this.contentLn+"|"+this.contentId+"|"+this.ContentCulture+"|"+this.exitContainerId+"|"+this.exitLinkId),this.enableCollTierParams&&this.logExternalUrls&&((!this.flexId||this.flexId.length==0)&&this.externalUrls.length>0&&(this.flexId="4"),this.flexValue10=this.externalUrls.join("|")),n=this.host+"?",this.sessionId!=""&&(n+="SessionID="+OutputEncoder_EncodeUrl(this.sessionId)+"&"),n+="SSID="+OutputEncoder_EncodeUrl(this.ssId)+"&SiteLCID="+OutputEncoder_EncodeUrl(this.siteLcId)+"&EventCollectionID="+OutputEncoder_EncodeUrl(this.eventCollectionId)+"&OptionCollectionId="+OutputEncoder_EncodeUrl(this.OptionCollectionId)+"&SSversion="+OutputEncoder_EncodeUrl(this.SsVersion)+"&ContentType="+OutputEncoder_EncodeUrl(this.contentType)+"&ContentLCID="+OutputEncoder_EncodeUrl(this.contentLn)+"&ContentID="+OutputEncoder_EncodeUrl(this.contentId)+"&ExitLinkID="+this.CleanId(this.exitLinkId)+"&ExitContainerID="+this.CleanId(this.exitContainerId)+"&DwellTime="+OutputEncoder_EncodeUrl(this.dwellTime)+"&BrandID="+OutputEncoder_EncodeUrl(this.siteBrandId)+"&SearchCategoryID="+this.CleanId(this.searchCategoryId+"")+"&SearchCategoryLinkPos="+OutputEncoder_EncodeUrl(this.searchCategoryLinkPos)+"&SearchPageLinkPos="+OutputEncoder_EncodeUrl(this.searchPageLinkPos)+"&TargetURL="+OutputEncoder_EncodeUrl(this.targetUrl)+"&EventSeqNo="+OutputEncoder_EncodeUrl(this.eventSeqNo)+"&SiteCulture="+OutputEncoder_EncodeUrl(this.SiteCulture)+"&ContentCulture="+OutputEncoder_EncodeUrl(this.ContentCulture)+"&Platform="+OutputEncoder_EncodeUrl(this.platform)+"&unload=true&FlexID="+OutputEncoder_EncodeUrl(this.flexId)+"&FlexValue1="+OutputEncoder_EncodeUrl(this.flexValue1)+"&FlexValue2="+OutputEncoder_EncodeUrl(this.flexValue2)+"&FlexValue3="+OutputEncoder_EncodeUrl(this.flexValue3)+"&FlexValue4="+OutputEncoder_EncodeUrl(this.flexValue4)+"&FlexValue5="+OutputEncoder_EncodeUrl(this.flexValue5),this.enableCollTierParams&&(t=document.getElementById("lb"),t!=null&&t.style.display!="none"?this.AddActiveTime(this.endDate):this.AddActiveTime(this.endDate,!0),this.suppressBlur=!0,n+="&ActiveDwellTime="+OutputEncoder_EncodeUrl(this.activeDwellTime)+"&FlexValue6="+OutputEncoder_EncodeUrl(this.flexValue6)+"&FlexValue7="+OutputEncoder_EncodeUrl(this.flexValue7)+"&FlexValue8="+OutputEncoder_EncodeUrl(this.flexValue8)+"&FlexValue9="+OutputEncoder_EncodeUrl(this.flexValue9)+"&FlexValue10="+OutputEncoder_EncodeUrl(this.flexValue10)),window.exitTabValue&&(n+="&ContentProperties="+OutputEncoder_EncodeUrl(exitTabID+"="+exitTabValue+"|")),$("#StatsDotNetImg").get(0).src=n,$("meta[name='ms.EventCollectionId']").attr("content",StatsDotNet.eventCollectionId),typeof MscomCustomEvent!="undefined"&&MscomCustomEvent("ms.ExitLinkID",OutputEncoder_EncodeUrl(StatsDotNet.exitLinkId),"ms.ExitContainerId",OutputEncoder_EncodeUrl(StatsDotNet.exitContainerId),"ms.IsUnLoad",OutputEncoder_EncodeUrl(!0),"ms.DwellTime",OutputEncoder_EncodeUrl(StatsDotNet.dwellTime)),i=new Date,r=i.getTime();for(;;){u=new Date,f=u.getTime();if(f-r>this.onUnloadTimeout)return}},this.SetExitLinks=function(n){var t=srcEl(n),r=null,u=null,i;if(!t)return;if(!t.tagName)return;if(t.tagName.toUpperCase()!="A")if(t.parentNode&&t.parentNode.tagName&&t.parentNode.tagName.toUpperCase()=="A")t=t.parentNode;else return;if(!t.href)return;if(t.href.indexOf("javascript:")>-1)return;if(t.href.indexOf("mailto:")>-1)return;t.id?this.exitLinkId=t.id:(this.exitLinkId="",(typeof isResetExitCID=="undefined"||isResetExitCID==null)&&(this.exitContainerId="")),this.targetUrl=t.href;if(this.enableCollTierParams&&this.logExternalUrls&&t.target&&t.target.toUpperCase()=="_BLANK"){for(i=0;i<this.externalUrls.length;i++)if(this.targetUrl.toLowerCase()==this.externalUrls[i])break;i<this.externalUrls.length||this.externalUrls.push(this.targetUrl.toLowerCase())}t.target.toUpperCase()==="_BLANK"&&(this.targetUrl="")},this.TrackSearch=function(n,t,i){this.searchCategoryId=n,this.searchCategoryLinkPos=t,this.searchPageLinkPos=i},this.GetCookieIncrement=function(){var t="sdninc",n=fetchcookieval(t);return n||(n="0"),n=parseInt(n),n+=1,document.cookie=t+"="+n+"; path=/;",n},this.SetSearchCategoryId=function(n){StatsDotNet.disabled||(this.searchCategoryId=n)},this.eventSeqNo=this.GetCookieIncrement()}function MS_HandleClick(n,t,i){var e,r,f,u,o;n.id||(n.id=""),e=n.id.replace("_i",""),i&&!StatsDotNet.disabled&&(StatsDotNet.exitLinkId=e,StatsDotNet.exitContainerId=t);switch(e){case"PrintPage":return SaveToFavoritesData.PrintPage();case"bil_PrintPage":return SaveToFavoritesData.PrintPage();case"EmailPage":return SaveToFavoritesData.EmailPage(n)}return n.id.indexOf("oas_")==0&&(n.href=MS_OASURL+GetModifiedQueryString("gprid",n.id.replace("oas_","")),r=n.href.toLowerCase().indexOf("target=assistance"),r>0&&(u=r+17,n.href.charAt(r-1)=="&"&&(r=r-1),n.href=n.href.substring(0,r)+n.href.substring(u,n.href.length))),n.href!=null&&(f=n.href.indexOf("GSSProdSelMore"),f>0&&(u=n.href.indexOf("&",f),u<0&&(u=n.href.length),o=n.href.substring(f+14,u),n.href="/select/default.aspx"+GetModifiedQueryString("c1",o))),!0}function getsearchurl(n){queryString.adv=="1"&&(n.href=n.href+"&adv=1")}function getrssurl(n){var t=n.href.indexOf("/common/rss.aspx");t>-1&&(n.href=n.href+"&msid="+mc1)}function MS_WebMetrix(n){if(typeof n!="undefined"){var t,i="guid=",r="&guid=",u=32;t=fetchcookieval("MC1"),t&&(t=t.toLowerCase()),t||(t=fetchcookieval("MC2"),t&&(t=t.toLowerCase())),t&&(t.substr(0,i.length)==i?mc1=t.substr(i.length,u):t.indexOf(r)>-1&&(mc1=t.substr(t.indexOf(r)+r.length,u))),n=n+"&msid="+mc1,$("#webmetriximg").get(0).src=n}}function MS_DocumentOnClick(n){StatsDotNet.disabled||StatsDotNet.SetExitLinks(n)}function MS_WindowOnUnload(){StatsDotNet.disabled||StatsDotNet.LogPageOnUnLoad()}function MS_WindowOnScroll(){StatsDotNet.scrollUsed=!0,$(document).unbind("scroll",MS_WindowOnScroll)}function OptionCookie(){var r=fetchcookieval("adopt"),u,t,n,i,f;if(r&&r.length>0)for(u=r.split("|"),t=0;t<u.length;t++){n=u[t].split("=");if(n.length!=2)continue;if(n[1]=="")continue;i=n[0],f=n[1],this[i]?this[i]+=", "+f:this[i]=f}}function InitRadio(n,t){tval=fetchcookieval("ad"+t);if(tval)for(i=0;i<n.length;i++)if(n[i].value==unescape(tval)){n[i].checked=!0,n[i].click();break}}function addPopupHelpEvents(){var i=0,t=$("#contentArea a"),n;if(t)for(n=t.length-1;n>=0;n--)t[n].className=="custip"&&(links.push(t[n]),t[n].onmouseover=showPopupHelp,t[n].onmouseout=hidePopupHelp,t[n].onfocus=showPopupHelp,t[n].onblur=hidePopupHelp)}function showPopupHelp(){var n=$(this).children("span")[0];if(n==null)return;var i=AbsPos(this),r=n.offsetWidth,u=n.offsetHeight+parseInt($(n).css("paddingTop"),10)+parseInt($(n).css("paddingBottom"),10),t="",f=$(n).css("direction");f==="rtl"?i.left<r?(t+=" showLeft",n.style.right="auto"):n.style.right="20px":r+i.left>$(window).width()&&(t+=" showRight"),u+i.top>$(window).height()&&(t+=" showBottom"),this.className="custip show"+t}function hidePopupHelp(){var n=null,t;this.className="custip";if(this.getElementsByTagName("span"))n=this.getElementsByTagName("span")[0];else return;if(n==null)return;t=$(n).css("direction"),t==="rtl"&&(n.style.right="auto")}function AbsPos(n){var t=y=0;if(n.offsetParent){t=n.offsetLeft,y=n.offsetTop;while(n=n.offsetParent)t+=n.offsetLeft,y+=n.offsetTop}return{left:t,top:y}}function setKeyBit(n){n=srcEl(n),n.keyBit=!0}function logSearchUISwitch(){StatsDotNet.eventCollectionId=SetLogCollectionBit(StatsDotNet.eventCollectionId,28)}function logRange(){StatsDotNet.eventCollectionId=SetLogCollectionBit(StatsDotNet.eventCollectionId,8)}function logOptionId(n){StatsDotNet.OptionCollectionId=SetLogCollectionBit(StatsDotNet.OptionCollectionId,n)}function IsLogBitSet(n,t){if(n==0||t==0)return!1;var i=n.toString(2);if(i.length>t)if(i.charAt(i.length-t-1)=="1")return!0;return!1}function SetLogCollectionBit(n,t){return IsLogBitSet(n,t)||(n+=Math.pow(2,t)),n}function SolIdForStatsNet(n){StatsDotNet.disabled||(StatsDotNet.flexId="4",StatsDotNet.flexValue1=n,StatsDotNet.eventCollectionId=SetLogCollectionBit(StatsDotNet.eventCollectionId,18))}function AssetIdClick(n){StatsDotNet.disabled||(StatsDotNet.SetSearchCategoryId(n),StatsDotNet.flexValue2=n,StatsDotNet.flexId="4")}function RegionSave(n){var t=n+"LANG",i=fetchcookieval(t),r=$("#LN").get(0).value;i&&i!=r&&(StatsDotNet.eventCollectionId=SetLogCollectionBit(StatsDotNet.eventCollectionId,17)),setcookieval(t,r),$("#regionform").get(0).submit}function CheckEulaCookie(n){var t=fetchcookieval("acweula");return t!="1"?!0:(StatsDotNet.eventCollectionId=SetLogCollectionBit(StatsDotNet.eventCollectionId,26),location.href=n,!1)}function LaunchAcw(n,t){if(n=="accept"){StatsDotNet.eventCollectionId=SetLogCollectionBit(StatsDotNet.eventCollectionId,26),setcookieval("acweula","1");var i=window.open(t,null,"height=1,width=1,left=0,top=0,status=no,toolbar=no,menubar=no,location=no");return i?$("[name=frmacw]").submit():location.href=t,!1}$("[name=frmacw]").submit()}function getLatestElement(){var n=$("body").get(0);while(n.lastChild)n=n.lastChild;while(!n.tagName)n=n.parentNode;return n.previousSibling}function fixBulletPosition(){return}function setACStartChars(n){n&&(acStartNum=n.split(":"))}function changeLcidForSelect(n,t,i,r){var u=i||n.options[n.selectedIndex].value;u&&(u=u.split("="),u.length===2&&changeAcLcid(u[1],t));if(acStartNum)try{chars=r?acStartNum[parseInt(r,10)]:acStartNum[n.selectedIndex],MS.Support.AC.ACChangeCharStart(t,chars)}catch(f){}}function InitAC(n){var t=function(){var r=$("#ddCatalog").get(0),t,u,i;if(r){t=unescape(fetchcookieval("adcatalog"));if(t){for(u=!1,i=0;i<r.options.length;i++)if(r.options[i].value==t){u=!0;break}if(u){t=t.split("=");if(t.length===2)try{MS.Support.AC.ACSetLcid(n,t[1])}catch(f){}}}}};$(window).ready(t)}function srch_setcookieval(n,t){setcookieval(n,t,null,!0)}function setcookieval(n,t,i,r){var u,s,h,c,e,l,f,o;if(!n)return;s="",r||(h=new Date,s+="; expires="+h.toGMTString(h.setFullYear(h.getFullYear()+1))),c=document.domain,typeof gCookieDomain!="undefined"&&gCookieDomain!=null&&gCookieDomain!=""&&(c=gCookieDomain),c.indexOf(".com")>-1&&(s+="; Domain="+c),u=fetchcookieval(n);if(u&&i){l=!1;if(u.indexOf("=")>-1){for(f=u.split("&"),o=0;o<f.length;o++){e=f[o].substring(0,f[o].indexOf("=")),e.charAt(0)==" "&&(e=e.substring(1,e.length));if(i===e){f[o]=i+"="+t,u=f.join("&"),l=!0;break}}l||(f.length>0&&(u+="&"),u+=i+"="+t)}else u=i+"="+t}else if(!u&&i)u=i+"="+t;else{if(i)return;u=t}document.cookie=n+"="+u+s+"; path=/"}function fetchcookieval(n,t){var u,f,r,i;if(!n)return"";for(r=document.cookie.split(";"),i=0;i<r.length;i++){u=r[i].substring(0,r[i].indexOf("=")),u.charAt(0)==" "&&(u=u.substring(1,u.length));if(n===u){f=r[i].substring(r[i].indexOf("=")+1,r[i].length);break}}if(f===undefined||f===null)return null;if(!t)return f;for(r=f.split("&"),i=0;i<r.length;i++){u=r[i].substring(0,r[i].indexOf("=")),u.charAt(0)==" "&&(u=u.substring(1,u.length));if(t===u)return r[i].substring(r[i].indexOf("=")+1,r[i].length)}return null}function onHotfixEulaAction(n,t){setcookieval("hotfixEulaCookie",n=="accept"?"1":"0","",!1),n=="accept"?document.forms.frmHotfixEula.submit():document.location.href=t}function AddtoSocialMedia(n,t,i,r){var u=window.location.href,f=window.document.title;LogSocialMedia(n,u,t),window.open(i+encodeURIComponent(u)+r+(jQuery.trim(r).length==0?"":encodeURIComponent(f)),"win")}function LogSocialMedia(n,t,i){var u="",r=new Date,f=r.getHours(),e=r.getMinutes(),o=r.toDateString();u="SSID=25&RequestDate="+o+"&HourID="+f+"&MinuteID="+e+"&FlexValue1="+n+"&PageUrl="+t+"&Flexid=1&Flexvalue2="+i+"&Flexvalue3="+StatsDotNet.contentId+"&SiteCulture="+StatsDotNet.SiteCulture+"&ContentCulture="+StatsDotNet.ContentCulture,$.ajax({url:"/lts/default.aspx",data:u})}function IsChildren(n,t,i){var u;if(!n)return!1;u=!1,i||(i=6);var r=n.parentNode,f=0,e=!1;while(r&&i>f){if(r==t){u=!0;break}r=$(r).parent().get(0),f++}return u}function ElementsByName(n,t){var i=document.getElementsByName(t),u,r;if(i.length>0)return i;for(i=[],u=document.getElementsByTagName(n),r=0;r<u.length;r++)u[r].getAttribute("name")==t&&(i[i.length]=u[r]);return i}function DisplayATList(){$("#ATList").css("display").toLowerCase()=="none"?($("#thinColumn").get(0)&&$("#thinColumn").css("overflow","visible"),$("#ATList").css("display","block"),$(document).bind("click.ArticleTranslation",function(n){ArticleTranslationClickHandle(n)})):($("#ATList").css("display","none"),$(document).unbind("click.ArticleTranslation"))}function ArticleTranslationClickHandle(n){if(!n||!n.target)return;var t=n.target,i=$("#ArticleTranslations").get(0);if(i==t||IsChildren(t,i))return;$("#ATList").css("display","none"),$(document).unbind("click.ArticleTranslation")}function ATClick(n,t){t.id="KBLangListRedirect",StatsDotNet.disabled||(StatsDotNet.exitContainerId=n)}function getSubMenuHandleName(n){return n.id?n.id:"dropdownmenu"}function bindMenuEvent(n){n.menuEventBound||(n.menuEventBound=!0,$(n).hover(null,function(){hideSubMenu(n)}),$(n).bind("keydown",function(t){t.keyCode===27&&($(n).find("a#menubody").focus(),hideSubMenu(n))})),n.menuGlobalTrackEventBound||(n.menuGlobalTrackEventBound=!0,$(document).bind("click."+getSubMenuHandleName(n),function(t){hideSubMenuHandle(t,n)}),$(document).bind("focusin."+getSubMenuHandleName(n),function(t){hideSubMenuHandle(t,n)}))}function displaySubMenu(n){$(n).find("#dropdownmenu").show(),bindMenuEvent(n)}function hideSubMenu(n){$(n).find("#dropdownmenu").hide(),$(document).unbind("click."+getSubMenuHandleName(n)),$(document).unbind("focusin."+getSubMenuHandleName(n)),n.menuGlobalTrackEventBound=!1}function toggleSubMenu(n){$(n).find("#dropdownmenu").is(":visible")?hideSubMenu(n):displaySubMenu(n)}function trackOutsideEvent(n,t,i){if(!n||!n.target)return;var r=n.target;jQuery.contains(t,r)||r==t||i(t)}function hideSubMenuHandle(n,t){trackOutsideEvent(n,t,function(n){hideSubMenu(n)})}function recordLinkClick(n,t){var i,r;t&&(i=StatsDotNet["flexValue"+n],i=$.trim(i),i?(r="|"+i+"|",r.indexOf("|"+t+"|")<0&&(i=i+"|"+t)):i=t,StatsDotNet["flexValue"+n]=i)}function handleFixitFooterClick(n,t){var i,r;if(!n||!n.target)return;i=n.target,$(i).is("a")&&(r=$(i).attr("href"),recordLinkClick(t,r))}function generateWedcsData(){var t="wedcsinc",u="MS0",n=fetchcookieval(t),f=fetchcookieval(u),i,r;f!=null&&n||(n=0),n=parseInt(n),n+=1,setcookieval(t,n,null,!1),i=fetchcookieval("GsfxSessionCookie"),r=[buildMeta("eventseqno",n),buildMeta("SsVersion",StatsDotNet.SsVersion),buildMeta("EventCollectionId",StatsDotNet.eventCollectionId),buildMeta("OptionCollectionId",StatsDotNet.OptionCollectionId),buildMeta("ContentProperties",StatsDotNet.ContentProperties),buildMeta("ContentLcid",StatsDotNet.contentLn),buildMeta("BrandId",StatsDotNet.siteBrandId),buildMeta("Intended404Url",StatsDotNet.In404Url),buildMeta("ReferrerContentType",StatsDotNet.rctype),buildMeta("ReferrerContentLcid",StatsDotNet.rclcid),buildMeta("ReferrerContentCulture",StatsDotNet.rcculture),buildMeta("ReferrerContentId",StatsDotNet.rcid),buildMeta("ReferrerExitLinkID",StatsDotNet.rexlid),buildMeta("ReferrerExitContainerID",StatsDotNet.rexcid),buildMeta("SessionId",i)].join(""),$(r).appendTo($("head"))}var queryString=new MS_QueryString,g_reSupportedHostnames,StatsDotNet=new MS_StatsDotNet,SaveToFavoritesData=new MS_PageToolsData,mc1,links,acStartNum,changeAcLcid,buildMeta,GSS;SaveToFavoritesData.objStatsDotNet=StatsDotNet,mc1="",$(window).unload(MS_WindowOnUnload),$(document).click(MS_DocumentOnClick),$(document).scroll(MS_WindowOnScroll),links=[],$(document).ready(addPopupHelpEvents),changeAcLcid=function(n,t,i){try{MS.Support.AC.ACSetLcid(t,n);if(acStartNum&&i)try{MS.Support.AC.ACChangeCharStart(t,acStartNum[i])}catch(r){}}catch(r){}},AjaxGet=function(n,t){var i,r;try{i=null,window.XMLHttpRequest?i=new XMLHttpRequest:window.ActiveXObject&&(i=new ActiveXObject("Msxml2.XMLHTTP"));if(i&&i!=null)i.open("GET",n,!0),i.setRequestHeader("Connection","close"),i.setRequestHeader("Content-Type","text/plain"),i.onreadystatechange=function(){i.readyState==4&&i.status==200&&AjaxCallbackFunc(t,i.responseText)},i.send(null);else return null}catch(u){return null}},$(window).load(function(){$("#ATList").get(0)&&($("#ATList").css("display","none"),$("#ATList").css("position","absolute"))}),buildMeta=function(n,t){return t===undefined||t===null?"":'<meta name="ms.'+n+'" content="'+t+'" />'},$(function(){$(".ShareButton").css("display","block");var n=function(){$(".MediaContent ul").slideUp("fast")};$(".ShareButton").click(function(){return $(".MediaContent ul").slideToggle("fast"),!1}),$(document).bind("click",n),$(".MediaContent").unbind("click",n)}),GSS=GSS||{},GSS.Utility=GSS.Utility||{},function(n){function i(t){var s,r,o,f,i,u,e;t||(t=""),s=/^(?:([^:\/?\#]+):)?(?:\/\/([^\/?\#]*))?([^?\#]*)(?:\?([^\#]*))?(?:\#(.*))?/,r=t.match(s),this.scheme=r[1]||null,this.authority=r[2]||null,this.path=r[3]||null,this.query=r[4]||null,this.fragment=r[5]||null,this.url=t,this.queryString={};if(this.query)for(o=this.query.split("&"),f=0;f<o.length;f++){i=o[f].split("=");if(i.length!=2)continue;if(i[1]=="")continue;try{u=decodeURIComponent(i[0]).toLowerCase(),e=decodeURIComponent(i[1])}catch(h){u=unescape(i[0]).toLowerCase(),e=unescape(i[1])}this.queryString[u]?this.queryString[u]+=","+e:this.queryString[u]=e}this.modifyQueryItems=function(t){n.extend(this.queryString,t)}}var r,t,u;i.prototype={constructor:i,toString:function(){var t="";return this.scheme&&(t+=this.scheme+":"),this.authority&&(t+="//"+this.authority),this.path&&(t+=this.path),this.query=n.param(this.queryString),this.query&&(t+="?"+n.param(this.queryString)),this.fragment&&(t+="#"+this.fragment),t}},GSS.Utility.URI=i,t=-1,u=function(i,f){n.ajax({url:f,type:"HEAD",processData:!1,success:function(){n("#"+i).attr("src",f),n("#"+i).show()},statusCode:{404:function(){if(t===r.length-1){n("#"+i).remove();return}t=t+1,u(i,r[t])}}})},GSS.Utility.SetImageSrc=function(n,t,i){r=t.split("|"),u(n,i)},GSS.Utility.DisplaySsbAd=function(){var t=fetchcookieval("MUID");if(!t)return;n(document).ready(function(){f(t,function(){n("#divSsbAdContent").show()})})},GSS.Utility.TryRedirectToSsb=function(n){var i=fetchcookieval("ssbvisited"),r=fetchcookieval("ssbreminder"),t=fetchcookieval("MUID");i===null&&r===null&&t&&f(t,function(){self.location=n})};var f=function(t,i){n.get("/content/OptService.ashx",null,function(n){o(t,n),e(n,",","IsSmallMediumBusiness")&&i()})},e=function(n,t,i){for(var u=n.split(t),f=!1,r=0;r<u.length;r+=1)if(u[r]===i){f=!0;break}return f},o=function(t,i){var r=new Date,u=r.toDateString(),f="SSID=25&RequestDate="+u+"&Url="+encodeURIComponent(StatsDotNet.url)+"&Flexid=1&Flexvalue2=SSBOPT&Flexvalue3="+t+"&Flexvalue4="+i+"&SiteCulture="+StatsDotNet.SiteCulture+"&ContentCulture="+StatsDotNet.ContentCulture+"&ContentID="+StatsDotNet.contentId+"&ContentType="+StatsDotNet.contentType+"&ActiveDwellTime="+StatsDotNet.activeDwellTime+"&EventSeqNo="+StatsDotNet.eventSeqNo;n.ajax({url:"/lts/default.aspx",data:f})}}(jQuery);