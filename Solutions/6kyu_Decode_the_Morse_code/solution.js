decodeMorse = function(morseCode){
  return morseCode.split('   ').map(word => word.split(' ').map(code => MORSE_CODE[code]).join('')).join(' ').trim();
}