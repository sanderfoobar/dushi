(function() {
  Module = {
    onRuntimeInitialized: function () {
      if (document.readyState === "complete") {
        dushify();
      } else {
        setTimeout(() => {
          console.log("called via setTimeout");
          dushify();
        }, 500);
      }
    }
  };

  function dushify() {
    let elements = document.getElementsByTagName('*');

    for (let i = 0; i < elements.length; i++) {
      let element = elements[i];
      let tagName = element.tagName;

      // ignore
      if (['SCRIPT', 'META', 'PRE', 'STYLE'].indexOf(tagName) >= 0)
        continue;

      _loopDom(element);
    }
  }

  function _loopDom(element){
    for (let j = 0; j < element.childNodes.length; j++) {
      let node = element.childNodes[j];

      if (node.nodeType === 3) {
        let _text = node.nodeValue;
        let endsWS = _text.substr(_text.length - 1);

        if (_text.replace("\n", "").trim().length < 2)
          continue;

        let dushi = Module.bezem(_text, 15, 12);
        let replacedText = _text.replace(_text, dushi);
        if(endsWS) replacedText += " ";

        element.replaceChild(document.createTextNode(replacedText), node);
      }
    }
  }
})();

