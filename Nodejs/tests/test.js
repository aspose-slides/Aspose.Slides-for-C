const {convert_to_pdf} = require("../build/Release/Aspose.Slides.Cpp.Nodejs.Addon.node");

let presentation = "./Files/HelloWorld.pptx";
let pdf = "./Files/HelloWorld.pdf"

console.log(`convert_to_pdf(${presentation}, ${pdf})`);

try
{
    convert_to_pdf(presentation, pdf);
}
catch(error)
{
    console.log(error.message);
}
