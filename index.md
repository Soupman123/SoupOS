<h2>{{ site.data.list.docs_list_title }}</h2>
<ul>
{% for item in site.data.list.toc %}
   <h3>{{ item.title }}</h3>
   {% for entry in item.subfolderitems %}
      <li><a href="https://soupman123.github.io/SoupOS{{ entry.url }}">{{ entry.page }}</a></li>
   {% endfor %}
{% endfor %}
</ul>

### What is SoupOS?
[SoupOS](http://github.com) is a computer operating system currently maintained & written by [Soupman123](https://github.com/Soupman123/). SoupOS is a hobby operating system not written to compete with other operating systems, and is currently just a small project.

### What can SoupOS do?
Some of the main features inlude but are not limmited to at this moment:
```
PS/2 Mouse
Basic Keyboard
Simple text rendering
PCI Devices
```

### How can I get involved / started?
To get involved you can download the source code [here](https://github.com/Soupman123/SoupOS/archive/master.zip), or download the compiled operating system image [here](https://github.com/Soupman123/SoupOS/raw/master/kernel/bin/SoupOS.img). There are also some great resources over at [@Absurdponcho](https://github.com/Absurdponcho)['s operating system](https://github.com/Absurdponcho/PonchoOS) if you would like to learn more about operating system development.

### Support
Currently you can support this project via staring this project on [github](https://github.com/Soupman123/SoupOS/), but more support options are coming soon.

### Legal
```“Soupman” License Condition v1.0, derived from the “Commons Clause” License Condition v1.0

The Software is provided to you by the Licensor under the License, as defined below, subject to the following conditions.

Without limiting other conditions in the License, the grant of rights under the License will not include, and the License does not grant to you, the right to Sell the Software, or modify the license for commercial use.

For purposes of the foregoing, “Sell” means practicing any or all of the rights granted to you under the License to provide to third parties, for a fee or other consideration (including without limitation fees for hosting or consulting/ support services related to the Software), a product or service whose value derives, entirely or substantially, from the functionality of the Software. Any license notice or attribution required by the License must also include this Soupman License Condition notice.

Software: SoupOS <br/>
License: “Soupman” License Condition v1.0 <br/>
Licensor: Soupman123```
