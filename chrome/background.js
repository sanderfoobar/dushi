// set correct plugin icon
chrome.storage.sync.get('enabled', (enabled) => {
  chrome.browserAction.setIcon({
    path: enabled ? "static/on.png" : "static/off.png"
  });
});

// enable/disable plugin
chrome.browserAction.onClicked.addListener(function (tab) {
  chrome.storage.sync.get('enabled', (enabled) => {
    enabled.enabled = !enabled.enabled;
    chrome.storage.sync.set({'enabled': enabled.enabled}, () => {
      chrome.browserAction.setIcon({
        path : enabled.enabled ? "static/on.png" : "static/off.png"
      });
    });
  });
});

// tab event listen
chrome.tabs.onUpdated.addListener(function(tabId, changeInfo, tab) {
  if(!changeInfo.hasOwnProperty("status") || changeInfo["status"] !== "loading") return;

  chrome.storage.sync.get('enabled', (enabled) => {
    if(enabled.enabled){
      chrome.tabs.executeScript(tab.ib, {
        file: 'build/inject.js'
      });
    }
  });
});

chrome.runtime.onInstalled.addListener(function() {
  chrome.storage.sync.set({enabled: true}, function() {
    console.log("xmrdsc pr0duct10nz");
  });
});
