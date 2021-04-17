from AsposeSlidesCppExtension import convert_to_pdf

if __name__ == "__main__":
    pres_path = "../Files/HelloWorld.pptx"
    pdf_path = "../Files/HelloWorld.pdf"
    
    convert_to_pdf(pres_path, pdf_path)