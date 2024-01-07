const firebaseConfig = {
    apiKey: "AIzaSyCCSymi53vBi5cfhEXCXoVKkzgXDBQo8t4",
    authDomain: "esp8266-790f0.firebaseapp.com",
    databaseURL: "https://esp8266-790f0-default-rtdb.asia-southeast1.firebasedatabase.app",
    projectId: "esp8266-790f0",
    storageBucket: "esp8266-790f0.appspot.com",
    messagingSenderId: "983299816938",
    appId: "1:983299816938:web:cf08b5c7b91a3fd1404693",
    measurementId: "G-QSR8BXRLM0"
};

// Initialize Firebase
firebase.initializeApp(firebaseConfig);


// getting reference to the database
var database = firebase.database();

//getting reference to the data we want
var dataRef1 = database.ref('sensor/kelembapan_tanah');
var dataRef2 = database.ref('DHT_11/Temperature');

//fetch the data
dataRef1.on('value', function (getdata1) {
    var humi = getdata1.val();
    document.getElementById('kelembapan_tanah').innerHTML = humi ;
})

dataRef2.on('value', function (getdata2) {
    var temp = getdata2.val();
    document.getElementById('temperature').innerHTML = temp + "&#8451;";
})




