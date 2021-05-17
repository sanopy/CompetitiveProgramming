Prism.plugins.autoloader.languages_path = 'https://cdnjs.cloudflare.com/ajax/libs/prism/1.16.0/components/'

const e = document.querySelectorAll('pre > code');

for (let i = 0; i < e.length; i++) {
  const path = e[i].getAttribute('data-src');
  if (path === null)
    continue;

  const req = new XMLHttpRequest();
  req.onreadystatechange = () => {
    if (req.readyState == 4) { // 通信の完了時
      if (req.status == 200) { // 通信の成功時
        e[i].innerHTML = escapeHTML(req.responseText);
      }
    }
  };
  req.open('GET', path, true);
  req.send(null);
}

function escapeHTML(str){
  str = str.replace(/&/g, '&amp;');
  str = str.replace(/>/g, '&gt;');
  str = str.replace(/</g, '&lt;');
  str = str.replace(/"/g, '&quot;');
  str = str.replace(/'/g, '&#x27;');
  str = str.replace(/`/g, '&#x60;');
  return str;
}