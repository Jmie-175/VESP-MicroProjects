//
let currentResult = '0';
let query = '-';
var nameRegex = /^[a-zA-Z\s\.]+$/;
var emailRegex = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$/;

function updateResult() {
    if (currentResult == '')
    currentResult = '0';
    document.getElementById('query').textContent = query;
    document.getElementById('result').textContent = currentResult;
}

function appendToResult(value) {
    query = '-';
    if (currentResult === '0' && value !== '.') {
        currentResult = value;
    } 
    else if (currentResult === 'Error' || currentResult === 'Infinity'){
        currentResult = value;
    }
    else {
        currentResult += value;
    }
    updateResult();
}

function backSpace() {
    if (currentResult != '0' && currentResult != 'Error' && currentResult != 'Infinity') {
        currentResult = currentResult.substring(0, currentResult.length - 1);
    }
    else {
        currentResult = '0';
    }
    updateResult();
}

function clearResult() {
    currentResult = '0';
    updateResult();
}

function calculateResult() {
    query = currentResult;
    try {
        currentResult = eval(currentResult).toString();
        updateResult();
    }
    catch (error) {
        currentResult = 'Error';
        updateResult();
    }
}

// Handle form submission
document.getElementById("feedbackForm").addEventListener("submit", function (e) {
    e.preventDefault();

    // Get form values
    var name = document.getElementById("name").value;
    var email = document.getElementById("email").value;
    var rating = document.querySelector('input[name="rating"]:checked').value;
    var comments = document.getElementById("comments").value;

    // Validate name and email using regular expressions
    if (!name.match(nameRegex)) {
        alert("Please enter a valid name.");
        return;
    }

    if (!email.match(emailRegex)) {
        alert("Please enter a valid email address.");
        return;
    }

    // You can now send the form data to a server for processing, or do something else with it
    // For now, let's just display the data
    alert("Feedback Submitted!\n\nName: " + name + "\nEmail: " + email + "\nRating: " + rating + "\nComments: " + comments);
});