document.addEventListener("DOMContentLoaded", function () {
    const loginForm = document.getElementById('loginForm');
    const registerForm = document.getElementById('registerForm');
    const loginUsernameError = document.getElementById('loginUsernameError');
    const loginPasswordError = document.getElementById('loginPasswordError');
    const registerUsernameError = document.getElementById('registerUsernameError');
    const registerPasswordError = document.getElementById('registerPasswordError');

    loginForm.addEventListener('submit', function (event) {
        event.preventDefault();
        const username = document.getElementById('username').value.trim();
        const password = document.getElementById('password').value.trim();
        if (validateInput(loginUsernameError, loginPasswordError, username, password)) {
            // 发送登录请求
            login(username, password);
        }
    });

    registerForm.addEventListener('submit', function (event) {
        event.preventDefault();
        const username = document.getElementById('registerUsername').value.trim();
        const password = document.getElementById('registerPassword').value.trim();
        if (validateInput(registerUsernameError, registerPasswordError, username, password)) {
            // 发送注册请求
            register(username, password);
        }
    });

    function validateInput(usernameError, passwordError, usernameId, passwordId) {
        let isValid = true;
        const username = document.getElementById(usernameId).value.trim();
        const password = document.getElementById(passwordId).value.trim();

        if (username === '') {
            usernameError.textContent = '用户名不能为空';
            usernameError.style.display = 'block';
            isValid = false;
        } else {
            usernameError.style.display = 'none';
        }

        if (password === '') {
            passwordError.textContent = '密码不能为空';
            passwordError.style.display = 'block';
            isValid = false;
        } else {
            passwordError.style.display = 'none';
        }

        return isValid;
    }

    function login(username, password) {
        const data = {
            username: username,
            password: password
        };

        const fetchData = {
            method: 'POST',
            body: JSON.stringify(data),
            headers: {
                'Content-Type': 'application/json'
            }
        };

        fetch('https://example.com/login', fetchData)
            .then(response => response.json())
            .then(data => {
                if (data.status === 1) {
                    alert('登录成功');
                    // 跳转到主页或其他用户页面
                    window.location.href = '/'; // 假设主页URL为'/'
                } else {
                    alert('登录失败');
                }
            })
            .catch(error => {
                console.error('Error:', error);
                alert('请求出错，请稍后再试');
            });
    }

    function register(username, password) {
        const data = {
            username: username,
            password: password
        };

        const fetchData = {
            method: 'POST',
            body: JSON.stringify(data),
            headers: {
                'Content-Type': 'application/json'
            }
        };

        fetch('https://example.com/register', fetchData)
            .then(response => response.json())
            .then(data => {
                if (data.status === 1) {
                    alert('注册成功');
                    // 跳转到登录页面
                    window.location.href = 'login.html';
                } else {
                    alert('注册失败');
                }
            })
            .catch(error => {
                console.error('Error:', error);
                alert('请求出错，请稍后再试');
            });
    }
});


document.addEventListener("DOMContentLoaded", function () {
    const loginForm = document.getElementById('loginForm');
    const loginUsernameError = document.getElementById('loginUsernameError');
    const loginPasswordError = document.getElementById('loginPasswordError');

    loginForm.addEventListener('submit', function (event) {
        event.preventDefault();
        const username = document.getElementById('username').value.trim();
        const password = document.getElementById('password').value.trim();

        // 验证用户名格式（例如，至少5个字符，包含字母和数字）
        const usernamePattern = /^[a-zA-Z0-9]{5,}$/;
        if (!usernamePattern.test(username)) {
            loginUsernameError.textContent = '用户名必须至少5个字符，包含字母和数字';
            loginUsernameError.style.display = 'block';
            return;
        }

        // 验证密码格式（例如，至少8个字符，包含字母和数字）
        const passwordPattern = /^(?=.*[a-zA-Z])(?=.*\d)[a-zA-Z\d]{8,}$/;
        if (!passwordPattern.test(password)) {
            loginPasswordError.textContent = '密码必须至少8个字符，包含字母和数字';
            loginPasswordError.style.display = 'block';
            return;
        }

        // 如果验证通过，发送登录请求
        const data = {
            username: username,
            password: password
        };

        const fetchData = {
            method: 'POST',
            body: JSON.stringify(data),
            headers: {
                'Content-Type': 'application/json'
            }
        };

        fetch('http://119.91.210.79:3000/login', fetchData)
            .then(response => response.json())
            .then(data => {
                if (data.status === 1) {
                    loginUsernameError.style.display = 'none';
                    loginPasswordError.style.display = 'none';
                    alert('登录成功');
                    // 跳转到主页或其他用户页面
                    window.location.href = '/'; // 假设主页URL为'/'
                } else {
                    loginPasswordError.textContent = '登录失败';
                    loginPasswordError.style.display = 'block';
                }
            })
            .catch(error => {
                console.error('Error:', error);
                alert('请求出错，请稍后再试');
            });
    });
});
