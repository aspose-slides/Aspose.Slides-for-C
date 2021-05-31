const {convert_to_pdf} = require("../build/Release/Aspose.Slides.Cpp.Nodejs.Addon.node");
const express = require("express");
const multer  = require("multer");
const path = require('path');  

const app = express();
  
app.use(express.static(__dirname));
app.use(multer({dest:"uploads"}).single("uploadedFile"));
app.post("/upload", function (req, res, next) {

    if (req.fileValidationError) {
        return res.send(req.fileValidationError);
    }
    else if (!req.file) {
        return res.send('Please select a file to convert');
    }
    else if (req.err instanceof multer.MulterError) {
        return res.send(err);
    }
    else if (req.err) {
        return res.send(err);
    }

    let newName = path.parse(req.file.originalname).name + '.pdf';
    let newPath = path.join(req.file.destination, newName);

    console.log(`convert_to_pdf(${req.file.path}, ${newPath})`);

    try
    {
        convert_to_pdf(req.file.path, newPath);
    }
    catch(error)
    {
        return res.send(error.message);
    }

    res.download(newPath, newName, function (err) {
        if (err) {
          console.log(err.message);
        } else {
          console.log("ok");
    }});
});

app.listen(8000);