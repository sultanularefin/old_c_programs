(function(n){n.bi.queue={_delay:350,_timerId:null,_queue:[],push:function(n){this._queue.push(n),this._timerId==null&&this._startTimer()},_tryProcess:function(){this._clearTimer(),n(":animated").length==0&&this._queue.length>0&&n.bi.record(this._queue.shift()),this._queue.length>0&&this._startTimer()},_startTimer:function(){this._clearTimer(),this._timerId=window.setTimeout(n.proxy(this._tryProcess,this),this._delay)},_clearTimer:function(){this._timerId!=null&&(window.clearTimeout(this._timerId),this._timerId=null)}}})(jQuery);