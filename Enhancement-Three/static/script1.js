document.addEventListener("DOMContentLoaded", function () {
    var searchForm = document.getElementById("search-form");
    searchForm.addEventListener("submit", function (event) {
      event.preventDefault();
      performSearch();
    });
  });
  
  function performSearch() {
    var animalType = document.getElementById("animal-type").value;
    var animalColor = document.getElementById("animal-color").value;
    var outcomeType = document.getElementById("outcome-type").value;
    var sortBy = document.getElementById("sort-by").value;
    var sortOrder = document.getElementById("sort-order").value;
  
    fetch("/search", {
      method: "POST",
      headers: {
        "Content-Type": "application/x-www-form-urlencoded",
      },
      body: new URLSearchParams({
        animalType: animalType,
        animalColor: animalColor,
        outcomeType: outcomeType,
        sortBy: sortBy,
        sortOrder: sortOrder,
      }),
    })
      .then(function (response) {
        return response.json();
      })
      .then(function (data) {
        displayResults(data);
      })
      .catch(function (error) {
        console.log(error);
      });
  }
  
  function displayResults(results) {
    var resultContainer = document.getElementById("result-container");
    resultContainer.innerHTML = "";
  
    if (results.length > 0) {
      var table = document.createElement("table");
      table.classList.add("result-table");
  
      // Create table header
      var headerRow = document.createElement("tr");
      var headerAnimalId = document.createElement("th");
      headerAnimalId.textContent = "Animal ID";
      var headerOutcomeType = document.createElement("th");
      headerOutcomeType.textContent = "Outcome Type";
      var headerBreed = document.createElement("th");
      headerBreed.textContent = "Breed";
      var headerColor = document.createElement("th");
      headerColor.textContent = "Color";
  
      headerRow.appendChild(headerAnimalId);
      headerRow.appendChild(headerOutcomeType);
      headerRow.appendChild(headerBreed);
      headerRow.appendChild(headerColor);
      table.appendChild(headerRow);
  
      // Create table rows
      results.forEach(function (result) {
        var row = document.createElement("tr");
  
        var animalId = document.createElement("td");
        animalId.textContent = result["animal_id"];
        var outcomeType = document.createElement("td");
        outcomeType.textContent = result["outcome_type"];
        var breed = document.createElement("td");
        breed.textContent = result["breed"];
        var color = document.createElement("td");
        color.textContent = result["color"];
  
        row.appendChild(animalId);
        row.appendChild(outcomeType);
        row.appendChild(breed);
        row.appendChild(color);
        table.appendChild(row);
      });
  
      resultContainer.appendChild(table);
    } else {
      var noResults = document.createElement("p");
      noResults.textContent = "No results found.";
      resultContainer.appendChild(noResults);
    }
  }
  