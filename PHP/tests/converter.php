<?php

$message = '';
if (isset($_POST['uploadBtn']) && $_POST['uploadBtn'] == 'Convert')
{
  if (isset($_FILES['uploadedFile']) && $_FILES['uploadedFile']['error'] === UPLOAD_ERR_OK)
  {
    $fileName = $_FILES['uploadedFile']['name'];
    $fileTmpPath = $_FILES['uploadedFile']['tmp_name'];
    $tmpDir = dirname($fileTmpPath);

    $newName = pathinfo($fileName)['filename'] . ".pdf";
    $newPath = $tmpDir .  DIRECTORY_SEPARATOR . $newName;
    
    error_log ("convert_to_pdf($fileTmpPath, $newPath)");
    
    try
    {
       convert_to_pdf($fileTmpPath, $newPath);
    }
    catch (Exception $e)
    {
       exit ("Failed to convert file " . $fileName . " to PDF. Exception: " . $e->getMessage());
    }
        
    header("Content-Description: File Transfer"); 
    header("Content-Type: application/octet-stream"); 
    header("Content-Disposition: attachment; filename=\"". $newName ."\""); 

    readfile ($newPath);
  }
  else
  {
    $message = 'There is some error in the file upload. Please check the following error.<br>';
    $message .= 'Error:' . $_FILES['uploadedFile']['error'];
    exit($message);
  }
}
