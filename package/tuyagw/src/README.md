SDK产物介绍
-----------  

```  
.
├── build_app.sh   # 编译脚本
├── CHANGE_LOG.md  # 版本变更信息
├── demos          # 示例代码
├── tools          # 工具代码，如Zigbee射频功能
├── Makefile
└── sdk
    ├── include    # SDK头文件
    └── lib        # SDK库文件
```  

快速编译  
--------  

1. 修改 `Makefile` 文件，将交叉编译工具链的路径配置到 `COMPILE_PREX` 变量。  
2. 运行 `sh build_app.sh demo_gw`，将编译出来的应用以及SDK库文件拷贝到目标系统，编译产生的应用位于 `output/demo_gw` 目录下。  
