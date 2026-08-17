import { useEffect, useState } from 'react'
import './App.css'

function App() {
  const [message, setMessage] = useState("");
  
  useEffect(() => {
    fetch('http://localhost:8000/api/')
    .then(Response => Response.json())
    .then(data => setMessage(data.message))
    .catch(error => console.log("Error fetching message: ", error));
  }, [])

  return (
    <>
      <div>
        <h1>Message from backend</h1>
        <p>{message || 'Loading...'}</p>
      </div>
    </>
  )
}

export default App
