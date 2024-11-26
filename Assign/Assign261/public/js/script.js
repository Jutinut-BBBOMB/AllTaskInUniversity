function submitLogin() {
    const username = document.getElementById("username").value;
    const password = document.getElementById("password").value;
    const role = document.getElementById("role").value;
    
    if (username && password && role) {
        const afterLoginElement = document.querySelector('.after-login');
        const formElement = document.querySelector('form');
        
        if (afterLoginElement) {
            afterLoginElement.classList.remove('hidden');
        } else {
            console.error('.after-login element not found.');
        }
        
        if (formElement) {
            formElement.classList.add('hidden');
        } else {
            console.error('form element not found.');
        }
        
        alert('Logged in successfully as ' + role);
    } else {
        alert('Please fill out all fields.');
    }
    
    fetch('https://restapi.tu.ac.th/api/v1/auth/Ad/verify', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
            'Application-Key': 'TU2a21ceb78b45517f313d737d469fa12fcf7d12de45dcfaef91d41ae443e513ec22dba6f6bb2dc9f72fab91f492918f40'
        },
        body: JSON.stringify({ username, password })
    })
    .then(response => response.json())
    .then(data => {
        document.getElementById('message').innerText = data.message;
    })
    .catch(error => console.error('Error:', error));
}

function togglePassword() {
    const passwordInput = document.getElementById("password");
    const toggleText = document.getElementById("toggle-password");
    if (passwordInput.type === "password") {
        passwordInput.type = "text";
        toggleText.innerText = "Hide";
    } else {
        passwordInput.type = "password";
        toggleText.innerText = "Show";
    }
}