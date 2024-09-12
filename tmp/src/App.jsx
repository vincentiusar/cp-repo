import React, { useState } from "react";

function App() {

    const [text, setText] = useState("aaa");

    const f = () => {
        setText("bbb");
    }

    return (
        <div>
            <button onClick={f}>aaaaaaaa</button>
            {text}
        </div>
    )
}

export default App;