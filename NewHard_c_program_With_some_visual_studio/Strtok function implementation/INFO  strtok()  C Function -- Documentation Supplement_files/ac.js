window.MS||(window.MS={}),MS.Support=MS.Support||{},MS.Support.AC=function(n){return typeof n=="undefined"?null:this.CreateAC(n)},MS.Support.AC.acarray||(MS.Support.AC.acarray=[]),MS.Support.AC.ACArrayEl=function(n){for(var t=0;t<MS.Support.AC.acarray.length;t++)if(MS.Support.AC.acarray[t].key===n)return MS.Support.AC.acarray[t].val;return null},MS.Support.AC.MakeAutoComplete=function(n){if(n.id){var t=new MS.Support.AC(n);MS.Support.AC.acarray.push({key:n.id,val:t})}},MS.Support.AC.SetCookie=function(n,t){var i=new Date,r;i.setFullYear(i.getFullYear()+1),r=document.domain,document.cookie=r.indexOf(".com")>-1?n+"="+t+"; expires="+i.toGMTString()+"; Domain="+r+"; path=/":n+"="+t+"; expires="+i.toGMTString()+"; path=/"},MS.Support.AC.FetchCookie=function(n){for(var i,u,f=!1,r=document.cookie.split(";"),t=0;t<r.length;t++){i=r[t].substring(0,r[t].indexOf("=")),i.charAt(0)==" "&&(i=i.substring(1,i.length)),u=r[t].substring(r[t].indexOf("=")+1,r[t].length);if(n==i){f=!0;break}}return f?u:"blank"},MS.Support.AC.AddEvent=function(n,t,i){n.attachEvent?n.attachEvent("on"+t,i):n.addEventListener(t,i,!0)},MS.Support.AC.KillEvent=function(n,t,i){n.detachEvent?n.detachEvent("on"+t,i):n.removeEventListener(t,i,!0)},MS.Support.AC.ACOutputSuggestions=function(n,t,i){MS.Support.AC.ACArrayEl(i).OutputSuggestions(n,t)},MS.Support.AC.ACErrorSuggestions=function(n,t,i){MS.Support.AC.ACArrayEl(i).ErrorSuggestions(n,t)},MS.Support.AC.ACSetLcid=function(n,t){MS.Support.AC.ACArrayEl(n).options.lcid=t},MS.Support.AC.ACChangeCharStart=function(n,t){MS.Support.AC.ACArrayEl(n).options.startChar=t},MS.Support.AC.prototype={CreateAC:function(n){var r,t,a,c,i,v,h,l,y;this.options={id:"",lcid:"",acURL:"",statsObj:"",startChar:4,bubbleside:"left",dropdirection:"down",dropupgap:0,autoFocus:!1,lndir:"ltr",acOldValue:"",acNewValue:"",doNextCall:!0,acNoVal:"",actimer:null,acgrowtimer:null,dobubble:!0,acbubbleintimer:null,acbubbleouttimer:null,bubblecharlimit:255,btopac:0,acQueryBox:null,acListDiv:null,acListWrap:null,acNode:null,acIframeHack:null,ACEllipsis:null,BubbleImgPath:null,ACBubbleTextNode:null,ACBubbleIframeHack:null,acMinWidth:150,acWidth:"parent",ACGrowAmount:18,acReservedKeys:[13,38,40],nonCharKeys:[9,16,17,18,19,20,27,33,34,35,36,37,39,46,112,113,114,115,116,117,118,119,120,121,122,123],achead:document.getElementsByTagName("head").item(0),imgpath:"/library/images/support/en-us/",offshiftList:0,borderColor:"#666666",charbolding:2,clrwin:navigator.userAgent.indexOf("AppleWebKit")==-1?"Window":"#FFF",clrwintxt:navigator.userAgent.indexOf("AppleWebKit")==-1?"#333333":"#000",clrhigh:navigator.userAgent.indexOf("AppleWebKit")==-1?"Highlight":"#CCC",clrhightxt:navigator.userAgent.indexOf("AppleWebKit")==-1?"HighlightText":"#000",handleResize:null},this.ACOptionsFill(this.options,n||{}),t=this.options;if(!t)return!1;if(typeof t.id=="string")r=document.getElementById(t.id);else if(typeof t.id=="object"&&t.id.nodeName=="INPUT")r=t.id;else return!1;this.options.lndir=this.ACComputedStyle(r,"direction"),t.bubbleside=t.bubbleside&&typeof t.bubbleside=="string"&&t.bubbleside=="left"?t.lndir=="rtl"?"right":"left":t.bubbleside&&typeof t.bubbleside=="string"&&t.bubbleside=="right"?t.lndir=="rtl"?"left":"right":"right",(t.lcid===""||typeof t.lcid=="undefined")&&(t.lcid&&typeof t.lcid=="string"||(t.lcid="1033")),t.acURL=t.acURL===""||typeof t.acURL=="undefined"?"http://autocomplete.support.microsoft.com":unescape(t.acURL);if(t.startChar&&(typeof t.startChar=="string"||typeof t.startChar=="number"))try{t.startChar=parseInt(t.startChar,10),t.startChar<2&&(t.startChar=2),t.startChar>8&&(t.startChar=8)}catch(p){t.startChar=4}if(r){a=document.createElement("input"),a.setAttribute("type","hidden"),a.setAttribute("id","idTxtFld"),r.parentNode.insertBefore(a,r),r.offsetWidth<t.acMinWidth&&(t.acMinWidth=r.offsetWidth),r.setAttribute("autocomplete","off"),c=document.createElement("DIV"),i=c.style,c.id="acListDiv"+r.id,i.margin=i.padding="0px",i.marginTop="-2px",i.visibility="hidden",i.zIndex="99",i.position="absolute",i.lineHeight="18px",this.options.dropdirection==="up"&&(i.bottom=r.offsetHeight+parseInt(r.style.borderWidth*2,10)+parseInt(r.style.paddingTop*2,10)+this.options.dropupgap+"px"),v=parseInt(t.acMinWidth,10),i.width=(v>12?v-13:0)+"px",i.border="1px solid "+t.borderColor,i.overflow="hidden",i.padding="10px 1px 10px 10px",i.background="#fff",i.fontSize="0.7em",i.fontFamily=this.ACComputedStyle(r,"fontFamily"),this.options.lndir=="rtl"&&(i.paddingRight="10px",i.paddingLeft="1px"),h=document.createElement("div"),h.id="acListWrapper"+r.id,h.style.position="relative",h.style.width=parseInt(v,10)+"px",h.style.height="1px",h.appendChild(c),r.parentNode.appendChild(h),t.acNode=document.createElement("div"),i=t.acNode.style,t.acNode.className="acSugDiv",i.whiteSpace="nowrap",i.width="100%",i.overflow="hidden",i.backgroundColor=t.clrwin,i.color=t.clrwintxt,i.cursor="pointer",t.ACEllipsis=document.createElement("span"),t.ACEllipsis.style.background=t.clrwin,t.ACEllipsis.style.position="absolute",t.ACEllipsis.innerHTML="...",t.ACEllipsis.className="ellipsis",t.ACEllipsis.style.lineHeight="16px",t.ACEllipsis.style.height="18px",t.lndir=="ltr"?t.ACEllipsis.style.right="-1px":t.ACEllipsis.style.left="-1px";var f=document.createElement("div"),e=document.createElement("div"),u=document.createElement("div"),s=document.createElement("div"),o=document.createElement("div");f.id="gss_ac_bttop",e.id="gss_ac_btbottom",u.id="gss_ac_bttxt",s.id="gss_ac_btarrow",o.id="gss_ac_btdiv",t.BubbleImgPath||(t.BubbleImgPath=t.acURL),f.style.background="url("+t.BubbleImgPath+"/images/bubble.png) no-repeat",e.style.background="url("+t.BubbleImgPath+"/images/bubble.png) 0px -11px no-repeat",u.style.background="#FCFCDD",u.style.border="1px solid #DEBB4F",u.style.borderWidth="0px 1px",e.style.lineHeight=f.style.lineHeight=f.style.height=e.style.height="10px",f.style.fontSize=e.style.fontSize="0px",f.style.width=e.style.width="200px",u.style.width="178px",u.style.position=f.style.position=e.style.position="relative",u.style.color="black",u.style.fontSize=".7em",u.style.fontFamily=c.style.fontFamily,u.style.overflowX="hidden",u.style.whiteSpace="normal",u.style.padding="0px 10px",o.style.position=s.style.position="absolute",s.style.top="0px",s.style.height="23px",s.style.width="34px",o.style.width="226px",o.style.top="90px",o.style.zIndex=999,t.bubbleside=="left"?(f.style.cssFloat=e.style.cssFloat=u.style.cssFloat=f.style.styleFloat=e.style.styleFloat=u.style.styleFloat="left",o.style.left="-220px",s.style.right="0px",s.style.background="url("+t.BubbleImgPath+"/images/bubble.png) 0px -22px no-repeat"):(o.style.left=c.offsetWidth+"px",s.style.left="1px",s.style.background="url("+t.BubbleImgPath+"/images/bubble.png) -35px -22px no-repeat",f.style.cssFloat=e.style.cssFloat=u.style.cssFloat=f.style.styleFloat=e.style.styleFloat=u.style.styleFloat="right"),o.appendChild(f),o.appendChild(u),o.appendChild(e),o.appendChild(s),t.ACBubbleTextNode=o,navigator.userAgent.indexOf("MSIE")>0&&parseInt(navigator.userAgent.charAt(navigator.userAgent.indexOf("MSIE")+5),10)<7&&(this.ACMakeIframeHack(h,c),l=document.createElement("iframe"),l.id="gss_ac_btiframe",l.style.width="226px",l.style.position="absolute",l.style.filter="alpha(opacity=0)",t.bubbleside=="left"?l.style.left="-220px":l.style.right="-220px",t.ACBubbleIframeHack=l),y=this,this.ACAddEvt(r,"keyup",function(n){y.ACInitSuggestions(n)}),this.ACAddEvt(r,"keydown",function(n){y.ACHandleKeysDown(n)}),this.ACAddEvt(document,"mouseup",function(n){y.ACClickHandler(n)}),t.acListDiv=c,t.acQueryBox=r,t.acListWrap=h,t.autoFocus&&r.createTextRange&&!document.location.hash&&this.ACFocus()}return this},ACFocus:function(){var r=this.options,n=r.acQueryBox,t=n.value.length,i;if(n.createTextRange){i=n.createTextRange();try{r.lndir==="rtl"?i.move("character",-t):i.move("character",t),i.select()}catch(u){}}else n.focus(),n.setSelectionRange&&(r.lndir==="rtl"?n.setSelectionRange(0,0):n.setSelectionRange(t,t))},ACOptionsFill:function(n,t){for(option in t)n[option]=t[option];return n},ACDoShowTarget:function(){clearTimeout(this.options.acgrowtimer),this.options.acListDiv.style.visibility!="visible"&&(this.options.acListDiv.style.height="18px",this.options.acListDiv.style.visibility="visible",this.ACIframeVisible(this.options.acListDiv.style.visibility));var n=this;this.options.acgrowtimer=setInterval(function(t){n.ACGrowWindow(t)},10)},ACDoHideTarget:function(){clearTimeout(this.options.acgrowtimer);if(this.options.acListDiv.style.visibility!="hidden"){var n=this;this.PopBubble(),this.options.acgrowtimer=setInterval(function(t){n.ACShrinkWindow(t)},10)}},ACDropWidth:function(){var n;return n=typeof this.options.acWidth=="number"?this.options.acWidth:typeof this.options.acWidth=="string"&&this.options.acWidth=="self"?this.options.acQueryBox.offsetWidth&&this.options.acQueryBox.offsetWidth>this.options.acMinWidth?this.options.acQueryBox.offsetWidth:this.options.acMinWidth:this.options.acQueryBox.parentNode.offsetWidth&&this.options.acQueryBox.parentNode.offsetWidth>this.options.acMinWidth?this.options.acQueryBox.parentNode.offsetWidth:this.options.acMinWidth,n=parseInt(n,10)-13,(n>=0?n:0)+"px"},ACGrowWindow:function(){for(var n=0,r,i,t=0;t<parseInt(this.options.acListDiv.childNodes.length,10);t++)n+=parseInt(this.options.acListDiv.childNodes[t].offsetHeight,10);n?(r=n<this.options.acListDiv.offsetHeight?-1:1,i=parseInt(this.options.acListDiv.style.height,10)+this.options.ACGrowAmount*r,this.options.acListDiv.style.height=i+"px",this.ACIframeSize(i),i<n-this.options.ACGrowAmount||(this.options.acListDiv.style.height=n+"px",this.ACIframeSize(n),clearTimeout(this.options.acgrowtimer))):(this.options.acListDiv.style.height="auto",this.ACIframeSize(this.options.acListDiv.style.height),clearTimeout(this.options.acgrowtimer)),this.options.handleResize&&this.options.handleResize(this.options.acListDiv)},ACShrinkWindow:function(){if(this.options.acListDiv.style.height!="auto"&&this.options.acListDiv){var t=parseInt(this.options.acListDiv.style.height,10)-12;t=t>0?t:0,this.options.acListDiv.style.height=t+"px",this.ACIframeSize(this.options.acListDiv.style.height),parseInt(this.options.acListDiv.style.height,10)<13&&(this.options.acListDiv.style.visibility="hidden",this.ACIframeVisible(this.options.acListDiv.style.visibility),clearTimeout(this.options.acgrowtimer))}else this.options.acListDiv.style.visibility="hidden",this.options.acListDiv.style.height="1px",this.ACIframeVisible(this.options.acListDiv.style.visibility),this.ACIframeSize(this.options.acListDiv.style.height),clearTimeout(this.options.acgrowtimer);this.options.handleResize&&this.options.handleResize(this.options.acListDiv)},ACGetSuggestions:function(){var t=document.getElementById("acScript"),n;t&&this.options.achead.removeChild(t),n=document.createElement("SCRIPT"),n.id="acScript",n.setAttribute("type","text/javascript"),n.src=this.options.acURL+"/ACSearchSuggest.aspx?eleid="+this.options.acQueryBox.id+"&lcid="+this.options.lcid+"&query="+encodeURIComponent(this.options.acOldValue),this.options.achead.appendChild(n)},ACClickHandler:function(n,t){var u=this.ACSrcEl(n),f=this.ACIsChild(u,this.options.acListDiv),e,i,r;return u===this.options.acQueryBox&&!t?!1:!f&&(!this.options.handleResize||!this.ACIsChild(u,this.options.acListDiv.parentNode))?(this.ACHideTarget(),!1):(e=!0,this.options.acListDiv&&(i=this.options.acQueryBox,r=this.options.acListDiv.childNodes[i.selectedIndex],f&&r&&(i.previousSibling.disabled=!1,i.previousSibling.setAttribute("name","qid"),i.previousSibling.value=r.getAttribute("suggestionId"),i.value=r.getAttribute("textVal"),i.focus(),this.ACSelectText(n),this.options.acOldValue=i.value,this.options.statsObj&&(this.options.statsObj.eventCollectionId=SetLogCollectionBit(this.options.statsObj.eventCollectionId,41)),e=!1),this.options.acListDiv&&f&&this.ACHideTarget()),e)},ACInitSuggestions:function(n){for(var i,r,u,t=0;t<this.options.acReservedKeys.length;t++)if(this.ACGetKeyCode(n)==this.options.acReservedKeys[t])return;i=this.options.acQueryBox,this.ACGetKeyCode(i)==9&&this.ACClickHandler(i),i.selectedIndex=-1,this.ACHighlight(),this.options.acNewValue=i.value?i.value.ACRemoveSpaces():"";if(this.options.acNoVal!==""){if(this.options.acNoVal.toLowerCase()==this.options.acNewValue.substring(0,this.options.acNoVal.length).toLowerCase())return;this.options.acNoVal=""}for(t=0;t<this.options.nonCharKeys.length;t++)if(this.ACGetKeyCode(n)==this.options.nonCharKeys[t]){i.previousSibling.disabled=!1;return}i.previousSibling.disabled=!0,this.options.acOldValue.toLowerCase()==this.options.acNewValue.toLowerCase()||this.options.acNewValue.length<this.options.startChar?this.options.acNewValue.length<this.options.startChar&&(this.options.doNextCall=!0,this.ACHideTarget(),this.options.acOldValue=this.options.acNewValue):(this.options.actimer&&clearTimeout(this.options.actimer),r=this,this.options.doNextCall||(u=new RegExp("^"+this.options.acOldValue.RemoveRegexChrs(),"i"),this.options.acNewValue.match(u)?this.ACHideTarget():this.options.doNextCall=!0),this.options.doNextCall&&(this.options.acOldValue=this.options.acNewValue,this.options.actimer=setTimeout(function(n){r.ACGetSuggestions(n)},100)))},ErrorSuggestions:function(){return},OutputSuggestions:function(n,t){var u,e,i,r,f,o;try{this.PopBubble();if(t===""){this.options.acNoVal=n,this.ACHideTarget();return}for(this.options.acNoVal="",this.options.statsObj&&(this.options.statsObj.eventCollectionId=SetLogCollectionBit(this.options.statsObj.eventCollectionId,40),this.options.statsObj.flexId=11,this.options.statsObj.flexValue1=n.substr(0,256)),u=[],i=0;i<t.length;i+=2)u.push(this.ACSuggestion(t[i],t[i+1]));u=this.ACSort(u);if(u.length===0){this.options.doNextCall=!1,this.ACHideTarget();return}for(e=this,this.options.acListDiv.innerHTML="",n=n.RemoveRegexChrs(),i=0;i<u.length;i++)r=this.options.acNode.cloneNode(!0),f=document.createElement("span"),r.setAttribute("suggestionId",u[i].ID),r.setAttribute("textVal",u[i].Suggestion),r.setAttribute("queryVal",n),f.className="gss_ac_dtxt",f.id=f.className+i,f.innerHTML=this.BoldChars(u[i].Suggestion,n),r.appendChild(f),this.ACAddEvt(r,"mouseover",function(n){e.acMouseHighlight(n)}),this.ACAddEvt(f,"mouseover",function(n){e.acMouseHighlight(n)}),this.ACAddEvt(r,"keyup",function(n){e.BlowBubble(n)}),this.ACAddEvt(r,"mouseover",function(n){e.BlowBubble(n)}),this.options.acListDiv.appendChild(r),f.offsetWidth>r.offsetWidth&&(r.setAttribute("balloon",!0),r.appendChild(this.options.ACEllipsis.cloneNode(!0)));this.ACDoShowTarget(),o=this.ACDropWidth(),this.options.acListDiv.parentNode.style.width=parseInt(o)-1+"px",this.options.acListDiv.style.width=o}catch(s){this.ACHideTarget()}},BoldChars:function(n,t){var i=n,f,u,r;try{i=i.replace(/</gi,"&lt;").replace(/>/gi,"&gt;"),t=t.replace(/</gi,"&lt;").replace(/>/gi,"&gt;");switch(this.options.charbolding){case 1:r=new RegExp(t,"i"),i=i.replace(r,"<b>$&</b>");break;case 2:r=new RegExp(t,"gi"),i=i.replace(r,"<b>$&</b>");break;case 3:for(f=t.split(/\s+/g),u=0;u<f.length-1;u++)r=new RegExp("(^|\\s)(?!<|</|<b>)("+f[u]+")(?!>|</b>)(\\b|\\s)","gi"),i=i.replace(r,"$1<b>$2</b>$3");r=new RegExp("(^|\\s)(?!<|</|<b>)("+f[u]+")(?!>|</b>)","gi"),i=i.replace(r,"$1<b>$2</b>");break;case 4:for(f=t.split(/\s+/g),u=0;u<f.length;u++)r=new RegExp("(?!<|</|<b>)("+f[u]+")(?!>|</b>)","gi"),i=i.replace(r,"<b>$&</b>")}}catch(e){return n}return i},BlowBubble:function(n){var t,i,r,u;if(!this.options.dobubble)return;t=this.ACSrcEl(n);while(t.tagName=="SPAN"||t.tagName=="B")t=t.parentNode;if(!t.getAttribute("balloon")){this.PopBubble();return}i=document.getElementById("gss_ac_btdiv"),r=document.getElementById("gss_ac_btiframe"),i||(this.options.acListDiv.parentNode.appendChild(this.options.ACBubbleTextNode),i=document.getElementById("gss_ac_btdiv"),this.options.ACBubbleIframeHack&&(this.options.acListDiv.parentNode.appendChild(this.options.ACBubbleIframeHack),r=document.getElementById("gss_ac_btiframe")),u=this,i.style.opacity=this.options.btopac,i.style.filter="progid:DXImageTransform.Microsoft.Alpha(style=0, opacity="+this.options.btopac+")",clearInterval(this.acbubbleintimer),this.options.acbubbleintimer=setInterval(function(){u.FadeInBubble()},5)),document.getElementById("gss_ac_bttxt").innerHTML=this.CharSubset(t.getAttribute("textVal"),t.getAttribute("queryVal")),i.style.top=t.offsetTop+t.offsetHeight/2+"px",this.options.bubbleside=="right"&&(i.style.left=this.options.acListDiv.style.width),r&&(r.style.top=i.style.top,r.style.height=i.offsetHeight+"px")},PopBubble:function(){var n=document.getElementById("gss_ac_btdiv"),t;n&&this.options.acbubbleouttimer==null&&(clearInterval(this.options.acbubbleouttimer),t=this,this.options.btopac=100,n.style.opacity=this.options.btopac/100,n.style.filter="progid:DXImageTransform.Microsoft.Alpha(style=0, opacity="+this.options.btopac+")",this.options.acbubbleouttimer=setInterval(function(){t.FadeOutBubble()},5))},FadeInBubble:function(){var n=document.getElementById("gss_ac_btdiv");n&&(this.options.btopac=this.options.btopac+10,n.style.opacity=this.options.btopac/100,n.style.filter="progid:DXImageTransform.Microsoft.Alpha(style=0, opacity="+this.options.btopac+")",this.options.btopac<100||(clearInterval(this.options.acbubbleintimer),this.options.btopac=0))},FadeOutBubble:function(){var n=document.getElementById("gss_ac_btdiv"),t=document.getElementById("gss_ac_btiframe");n&&(this.options.btopac=this.options.btopac-10,n.style.opacity=this.options.btopac/100,n.style.filter="progid:DXImageTransform.Microsoft.Alpha(opacity="+this.options.btopac+")",this.options.btopac>0||(clearInterval(this.options.acbubbleouttimer),this.options.acbubbleouttimer=null,this.options.btopac=0,t&&t.parentNode.removeChild(t),n.parentNode.removeChild(n)))},CharSubset:function(n){var i=n.substring(0,this.options.bubblecharlimit);return n.length>this.options.bubblecharlimit&&(i+="..."),i},ACSort:function(n){var t=function(n,t){return n.Suggestion.length-t.Suggestion.length};return n.sort(t)},ACAddEvt:function(n,t,i){MS.Support.AC.AddEvent(n,t,i)},ACKillEvt:function(n,t,i){MS.Support.AC.KillEvent(n,t,i)},ACHandleKeysDown:function(n){var r=this.ACGetKeyCode(n),t=this.ACSrcEl(n),o=this.ACDropWidth(),f;this.options.acListDiv.parentNode.style.width=parseInt(o)-1+"px",this.options.acListDiv.style.width=o;if(this.options.acListDiv&&this.options.acListDiv.style&&this.options.acListDiv.style.visibility!="hidden"){var e=this.options.acListDiv.childNodes.length,i=t.selectedIndex,u=this.options.acListDiv.childNodes;if(r==40)return i<e-1?t.selectedIndex++:i<e-1||(t.selectedIndex=-1),i=t.selectedIndex,this.ACHighlight(),i<0?(t.value=this.options.acOldValue,this.PopBubble()):(f=u[i].getAttribute("textVal"),f!=null&&(t.previousSibling.disabled=!1,t.previousSibling.setAttribute("name","qid"),t.previousSibling.value=u[i].getAttribute("suggestionId"),t.value=f),this.BlowBubble(u[i])),this.ACSelectText(n),n.returnValue=!1,!1;if(r==38)return i<0?i==-1&&(t.selectedIndex=e-1):t.selectedIndex--,i=t.selectedIndex,this.ACHighlight(),i<0?(t.value=this.options.acOldValue,this.PopBubble()):(f=u[i].getAttribute("textVal"),f!=null&&(t.value=f),this.BlowBubble(u[i])),this.ACSelectText(n),n.returnValue=!1,!1;if(r==13&&i>-1)return n.returnValue=this.ACClickHandler(u[i]),this.ACStopDefault(n),n.returnValue;if(r==27)return this.ACHideTarget(),t.value=this.options.acOldValue,t.focus(),this.ACSelectText(n),n.returnValue=!1,!1;r==9&&this.ACClickHandler(n,!0)}else if(r==27)return t.value="",t.focus(),this.ACSelectText(n),n.returnValue=!1,!1},ACSelectText:function(n){if(!this.options.acOldValue)return;if(this.options.acQueryBox.createTextRange){var t=this.options.acQueryBox.createTextRange();t.moveStart("character",this.options.acOldValue.length),t.select()}else this.options.acQueryBox.setSelectionRange&&(this.options.acQueryBox.focus(),this.options.acQueryBox.setSelectionRange(this.options.acOldValue.length,this.options.acQueryBox.value.length));this.ACStopDefault(n)},acMouseHighlight:function(n){var t=this.ACSrcEl(n),r,i;while(t.tagName=="SPAN"||t.tagName=="B")t=t.parentNode;for(r=this.options.acListDiv.childNodes,i=0;i<r.length;i++)r[i]==t&&(this.options.acQueryBox.selectedIndex=i);this.ACHighlight()},ACHighlight:function(){for(var t=this.options.acListDiv.childNodes,n=0;n<t.length;n++)t[n].className=="acSugDiv"&&(n!=this.options.acQueryBox.selectedIndex?(this.HighlightEls(t[n],"background",this.options.clrwin),this.HighlightEls(t[n],"color",this.options.clrwintxt)):(this.HighlightEls(t[n],"background",this.options.clrhigh),this.HighlightEls(t[n],"color",this.options.clrhightxt)))},HighlightEls:function(n,t,i){if(n&&n.tagName){n.style[t]=i;if(n.childNodes)for(var r=0;r<n.childNodes.length;r++)this.HighlightEls(n.childNodes[r],t,i)}},ACStopDefault:function(n){window.event?(window.event.cancelBubble=!0,window.event.returnValue=!1):n.preventDefault&&n.preventDefault()},ACHideTarget:function(){this.options.acListDiv&&(this.ACDoHideTarget(),this.options.acQueryBox.selectedIndex=-1)},ACGetKeyCode:function(n){return n?n.keyCode?n.keyCode:n.charCode?n.charCode:null:null},ACComputedStyle:function(n,t){var i="";return document.defaultView&&document.defaultView.getComputedStyle?i=document.defaultView.getComputedStyle(n,null)[t]:n.currentStyle&&(t=t.replace(/-(w)/g,function(n,t){return t.toUpperCase()}),i=n.currentStyle[t]),i},ACIsChild:function(n,t){if(!n||!t)return!1;var i=n.parentNode;return t==i?!0:i?this.ACIsChild(i,t):!1},ACSrcEl:function(n){if(n){if(n.srcElement)return n.srcElement;if(n.target)return n.target}return n},ACMakeIframeHack:function(n,t){if(!this.options.acIframeHack){this.options.acIframeHack=document.createElement("IFRAME");var i=this.options.acIframeHack.style,r=t.style;i.marginTop=r.marginTop,i.left=r.left,i.top=r.top,i.visibility=r.visibility,i.width="100%",i.height="0px",i.position=r.position,this.options.acIframeHack.style.filter="progid:DXImageTransform.Microsoft.Alpha(style=0,opacity=0)",this.options.acIframeHack.src="",n.appendChild(this.options.acIframeHack),this.ACIframeSize=function(n){i.height=n},this.ACIframeVisible=function(n){i.visibility=n}}},ACSuggestion:function(n,t){return{ID:n,Suggestion:t}},ACIframeSize:function(){},ACIframeVisible:function(){}},String.prototype.RemoveRegexChrs=function(){var n=new RegExp("(\\\\|\\.|\\+|\\$|\\?|\\*|\\(|\\)|\\[|\\]|\\^|\\!)","g");return this.replace(n,"\\$1")};var dbcsSpaceRE=new RegExp(String.fromCharCode(12288),"g");String.prototype.ACRemoveSpaces=function(){var n=this.replace(dbcsSpaceRE," ");return n=n.replace(/^\s+|\s+$/g,""),n.replace(/\s\s+/g," ")};