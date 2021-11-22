module("luci.controller.myapp.new_tab", package.seeall)  --notice that new_tab is the name of the file new_tab.lua
 function index()
     entry({"admin", "new_tab"}, firstchild(), "New tab", 60).dependent=false  --this adds the top level tab and defaults to the first sub-tab (tab_from_cbi), also it is set to position 30
     entry({"admin", "new_tab", "tab_from_view"}, template("view_tab"), "View Tab", 2)  --this adds the second sub-tab that is located in <luci-path>/luci-myapplication/view and the file is called view_tab.htm, also set to the second position
end