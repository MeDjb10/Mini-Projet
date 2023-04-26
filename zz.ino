// Sketch pour piloter la led integree a la Wemos D1 mini depuis le reseau WiFi

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
const char *ssid = "DESKTOP-J7N4R0M 0988"; // Identifiant du WiFi que vous utilisez
const char *password = "80D[860i";         // Mot de passe WiFi que vous utilisez
ESP8266WebServer server(80);               // On demande un serveur qui ecoute sur le port 80

int led = 2; // La diode LED intégrée à la carte est branchée sur la broche GPIO2 (D4)
String etatGPIO2 = "ON";

// Ecrire une page Web HTML
String WebPage()
{
  String page = ""
                "
                < !DOCTYPE html >
                <html lang = 'en'>
                <head>
                <meta charset = 'UTF-8' />
                <meta http - equiv = 'X-UA-Compatible' content = 'IE=edge' />
                <meta name = 'viewport' content = 'width=device-width, initial-scale=1.0' />
                <!--start font-->
                <link rel = 'preconnect' href = 'https://fonts.googleapis.com' />
                <link rel = 'preconnect' href = 'https://fonts.gstatic.com' crossorigin />
                <link
                     href = 'https://fonts.googleapis.com/css2?family=Poppins:ital,wght@0,200;0,300;0,400;0,500;0,600;0,700;0,800;0,900;1,100;1,200;1,300;1,400;1,500;1,600;1,700;1,800;1,900&display=swap' rel = 'stylesheet' />
                <!--end font-->

                <link
                     rel = 'stylesheet' href = 'https://cdn.jsdelivr.net/npm/@fortawesome/fontawesome-free@6.2.1/css/fontawesome.min.css' integrity = 'sha384-QYIZto+st3yW+o8+5OHfT6S482Zsvz2WfOzpFSXMF9zqeLcFV0/wlZpMtyFcZALm' crossorigin = 'anonymous' />
                <title> Page</ title>
                <script></ script>
                <style>
                    *
  {
  margin:
    0;
  padding:
    0;
    box - sizing : border - box;
  }
  body
  {
    font - family : 'Poppins', sans - serif;
  position:
    relative;
    min - height : 100vh;
  }

#loader {
position:
  absolute;
left:
  0;
right:
  0;
bottom:
  0;
top:
  0;
background:
  red;
}

#message {
text - align : center;
color : red;
font - style : italic;
font - size : small;
height : 20px;
}

form
{
  padding - top : 200px;
}

.form - box
{
width:
  500px;
background:
  rgba(0, 0, 0, 0.8);
margin:
  auto;
padding:
  50px 0;
color:
#fff;
  box - shadow : 0 0 20px 2px rgba(0, 0, 0, 0.5);
}
h1
{
  text - align : center;
}
.input - box
{
margin:
  15px auto;
width:
  80 % ;
  border - bottom : 1px solid #fff;
padding:
  8px 0;
}
.input - box input
{
width:
  90 % ;
border:
  none;
outline:
  none;
background:
  transparent;
color:
#fff;
}

::placeholder
{
color:
#ccc;
}
.login - btn
{
margin:
  40px auto 20px;
width:
  80 % ;
display:
  block;
outline:
  none;
padding:
  10px 0;
border:
  1px solid #fff;
cursor:
  pointer;
background:
  transparent;
color:
#fff;
  font - size : 16px;
}
</ style>
    </ head>
    <body>
    <script type = 'module'>
        import{initializeApp} from 'https://www.gstatic.com/firebasejs/9.17.2/firebase-app.js';
import{
    getAuth,
    onAuthStateChanged,
    signInWithEmailAndPassword,
    signOut,
} from 'https://www.gstatic.com/firebasejs/9.17.2/firebase-auth.js';

// Your web app's Firebase configuration
const firebaseConfig = {
  apiKey : 'AIzaSyBOVdBVt41Gqil-iR94E36sys3-zvwn93s',
  authDomain : 'mini-projet-6d617.firebaseapp.com',
  projectId : 'mini-projet-6d617',
  storageBucket : 'mini-projet-6d617.appspot.com',
  messagingSenderId : '292278659148',
  appId : '1:292278659148:web:2ca6feb4f66f59e075ece9',
  measurementId : 'G-TVBKEYNMB9',
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const auth = getAuth(app);

const loginForm = document.f;
const login_btn = document.getElementById('login-btn');
const message = document.getElementById('message');

loginForm.addEventListener(
    'submit', (e) = > {
      e.preventDefault();
      login_btn.value = 'Login...';
      login_btn.disabled = true;
      // login_btn.value = 'login...';
      // login_btn.disabled = true;
      message.value = 'You are logged in';
      const email = loginForm.email.value;
      const password = loginForm.password.value;

      signInWithEmailAndPassword(auth, email, password)
          .then((userCredential) = > {
            // User signed in successfully...
            const user = userCredential.user;
            console.log('Logged in user:', user);
            login_btn.value = 'Login';
            login_btn.disabled = false;
          })
          .catch((error) = > {
            // Handle login errors...
            console.error('Login failed:', error);
            message.innerText = 'invalid email or password';
            login_btn.value = 'Login';
            login_btn.disabled = false;
          });
    });
const loader = document.getElementById('loader');
const admin_page = document.getElementById('admin_page');
const authentication_page = document.getElementById(
    'authentication_page');
const admin_name = document.getElementById('admin_name');

onAuthStateChanged(
    auth, (user) = > {
      if (user)
      {
        // User is logged in, show the protected form
        loader.style.display = 'none';
        admin_page.style.display = 'block';
        authentication_page.style.display = 'none';
        admin_name.innerHTML = user.email.replace('@gmail.com', '');
      }
      else
      {
        // User is not logged in, hide the protected form
        loader.style.display = 'none';
        admin_page.style.display = 'none';
        authentication_page.style.display = 'block';
      }
    });

// Handle logout button click
const logoutButton = document.getElementById('logout-btn');

logoutButton.addEventListener(
    'click', () = > {
      signOut(auth);
    });

function submitForm()
{
  document.getElementById('myForm').submit();
}
</ script>

    <div id = 'loader'> loading...</ div>
    <div id = 'authentication_page'>
    <form name = 'f'>
    <div class = 'form-box'>
    <h1> Login</ h1>
    <p id = 'message'></ p>
    <div class = 'input-box'>
    <input type = 'email' name = 'email' placeholder = 'Email' required />
    </ div>
    <div class = 'input-box'>
    <input
         type = 'password' name = 'password' placeholder = 'Password' required />
    </ div>
    <button type = 'submit' class = 'login-btn' id = 'login-btn'> Login</ button>
    </ div>
    </ form>
    </ div>

    <div id = 'admin_page'>
    <p> admin</ p>
    <p id = 'admin_name'></ p>

    <form method = 'POST' id = 'myForm' name = 'myForm'>
    <div id = 'command-etat'>
    <h3> Commande d 'une LED sur GPIO</h3> <div id = ' etat '> GPIO2 : <span> """ page += etatGPIO2; page += "" " ON</ span></ div></ div> <label> <input type = ' radio ' name = ' GPIO2 ' value = ' 1 ' onchange = ' submitForm() ' id = ' ON' / > <span> ON</ span> </ label>
    <label>
    <input type = 'radio' name = 'GPIO2' value = '0' onchange = 'submitForm()' />
    <span> OFF</ span>
    </ label>
    </ form>

    <button id = 'logout-btn'> logout</ button>
    </ div>
    </ body>
    </ html>
    </ span></ div>
    </ div>
    <label>
    <input
         type = 'radio' name = 'GPIO2' value = '1' onchange = 'submitForm()' id = 'ON' />
    <span> ON</ span>
    </ label>
    <label>
    <input type = 'radio' name = 'GPIO2' value = '0' onchange = 'submitForm()' />
    <span> OFF</ span>
    </ label>
    </ form>
    <br /><br />
    <p id = 'iset_ch'><a href = '#'> ISET Charguia &copy;</a></p>
    </div>
    <div id='unsecured_page'>
      <form method='POST' id='login-form'>
        <h1 class='title'>Login</h1>
        <div id='message'></div>
        <label for='email'>Email</label>
        <input type='email' name='email' id='email' required />
        <label for='password'>Password</label>
        <input type='password' name='password' id='password' required />
        <input type='submit' value='login' id='submit_login' />
      </form>
    </div>
  </body>
</html>
  """    

return page;
}
* /

    void Racine()
{
  if (server.hasArg("GPIO2"))
  {
    Soumettre();
  }
  else
  {
    server.send(200, "text/html", WebPage());
  }
}

void Soumettre()
{
  // Actualise le GPIO
  String GPIOValue;
  GPIOValue = server.arg("GPIO2");
  Serial.print("Set GPIO to ");
  Serial.println(GPIOValue);
  if (GPIOValue == "1")
  {
    digitalWrite(2, 0);
    etatGPIO2 = "ON";
    server.send(200, "text/html", WebPage());
  }
  else if (GPIOValue == "0")
  {
    digitalWrite(2, 1);
    etatGPIO2 = "OFF";
    server.send(200, "text/html", WebPage());
  }
  else
  {
    Serial.println("Erreur Valeur LED");
  }
}

void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // on attend d'etre connecté au WiFi avant de continuer
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  // on affiche l'adresse IP qui nous a ete attribuée
  Serial.println("");
  Serial.print("Addresse IP : ");
  Serial.println(WiFi.localIP());
  // on definit les points d'entree (les URL a saisir dans le navigateur web) et on affiche un simple texte
  server.on("/", Racine);

  // on demarre le serveur web
  server.begin();
  pinMode(led, OUTPUT); // Initialise la broche GPIO2 comme une sortie
}

// Cette boucle s'exécute à l'infini
void loop()
{
  // a chaque iteration, on appelle handleClient pour que les requetes soient traitees
  server.handleClient();
}