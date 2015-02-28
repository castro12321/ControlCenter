function log(str)
{
	document.getElementById("recognised").innerHTML += (str + "<br>");
}

var targetAddress = "http://localhost:820/speech/";

function httpGet(message)
{
	$.ajax({
			url: targetAddress+message,
			dataType: 'jsonp',
			type: 'GET',
	});
}

(function() {
	// Get some required handles
	var recStatus   = document.getElementById('recStatus');
	var startRecBtn = document.getElementById('startRecBtn');
	var stopRecBtn  = document.getElementById('stopRecBtn');

	// Define a new speech recognition instance
	var rec = null;
	try {
		rec = new webkitSpeechRecognition();
	} 
	catch(e) {
    	document.querySelector('.msg').setAttribute('data-state', 'show');
    	startRecBtn.setAttribute('disabled', 'true');
    	stopRecBtn.setAttribute('disabled', 'true');
    }
    if (rec) {
		rec.continuous = true;
		rec.interimResults = false;
		//rec.lang = 'en';
		rec.lang = 'pl';

		// Process the results when they are returned from the recogniser
		rec.onresult = function(e) {
			// Check each result starting from the last one
			for (var i = e.resultIndex; i < e.results.length; ++i) {
				// If this is a final result
	       		if (e.results[i].isFinal) {
                    // Define a threshold above which we are confident(!) that the recognition results are worth looking at
                    var confidenceThreshold = 0.5;
	       			// If the result is equal to or greater than the required threshold
	       			if (parseFloat(e.results[i][0].confidence) >= parseFloat(confidenceThreshold)) {
		       			var str = e.results[i][0].transcript;
		       			console.log('Recognised: ' + str);
		       			// If the user said 'video' then parse it further
						
						// TODO: handle recognised string
						log(str);
						httpGet(str);
	       			}
	        	}
	    	}
		};
		
		rec.onend = function() {
			rec.start();
		}
		
		// Start speech recognition
		var startRec = function() {
			rec.start();
			recStatus.innerHTML = 'recognising';
		}
		// Stop speech recognition
		var stopRec = function() {
			rec.stop();
			recStatus.innerHTML = 'not recognising';
		}
		// Setup listeners for the start and stop recognition buttons
		startRecBtn.addEventListener('click', startRec, false);
		stopRecBtn.addEventListener('click', stopRec, false);
	}
})();