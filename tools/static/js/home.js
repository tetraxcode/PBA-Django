// This function is called whenever the browser is loaded
window.onload = function() {
  file_name = sessionStorage.getItem("selected_file")

  if(sessionStorage.getItem('show_lab_averages') === 'true') {
    document.getElementById("lab_averages").style.display = "block";
  }

  if(sessionStorage.getItem("show_roster") === "true") {
    document.getElementById("roster-div").style.display = "block";
  }
  else {
    document.getElementById("roster-div").style.display = "none";
  }
  
  if(file_name != null) {
    document.getElementById("selected_file").innerText = "Selected file: " + file_name;
  } 
  else {
    document.getElementById("selected_file").innerText = "Selected file: ";
  }
  
}

function show_lab_averages() {
  // document.getElementById("lab_averages").style.display = "block";
  sessionStorage.setItem('show_lab_averages', 'true'); //store state in localStorage
}

function show_roster() {
  // document.getElementById("roster-div").style.display = "block";
  sessionStorage.setItem("show_roster", "true");
}

function upload_form_validation() {
  file_name = document.getElementById("log_file_input").value
  if(file_name == "") {
    alert("Please select a log file to continue")
    return false
  }
  else {
    file_name = file_name.replace('C:\\fakepath\\', ' ')
    document.getElementById("selected_file").innerText = "Selected file:" + file_name
    sessionStorage.setItem("selected_file", file_name)
    sessionStorage.setItem("show_roster", "false");
    return true
  }
}

function set_selected_file() {
  const filename = document.getElementById("log_file_input").value.replace('C:\\fakepath\\', ' ')
  document.getElementById("selected_file").innerText = "Selected file:" + filename
}