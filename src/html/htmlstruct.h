﻿#ifndef HTMLSTRUCT_H
#define HTMLSTRUCT_H

#include <QString>
#include <QStringList>
#include <QSharedPointer>

namespace Html{

struct NodeHtml{
    //文档结构
    const QString HTML = "html";
    const QString HEAD = "head";
    const QString BODY = "body";
    const QString TITLE = "title";
    const QString META = "meta";
    const QString LINK = "link";
    const QString SCRIPT = "script";

    //元素
    const QString DIV = "div";
    const QString INPUT = "input";
    const QString P = "p";
    const QString SPAN = "span";
    const QString IFRAME = "iframe";

    //属性
    const QString ID = "id";
    const QString CLASS = "class";
    const QString STYLE = "style";
    const QString TYPE = "type";
    const QString SRC = "src";
    const QString HREF = "href";
    const QString VALUE = "value";
    const QString CHECKED = "checked";
    const QString DISABLED = "disabled";
    const QString SELECTED = "selected";
    const QString READONLY = "readonly";
    const QString MAX_LEN = "maxlength";
    const QString DATA_LABEL = "data-label";
    const QString DATA_LEFT = "data-left";
    const QString DATA_TOP = "data-top";
    const QString DATA_WIDTH = "data-width";
    const QString DATA_HEIGHT = "data-height";
    const QString SELECTIONGROUP = "selectiongroup";


};

/*!
 * @brief 控件类型
 */
enum NodeType{
    RINVALID,
    RCONTAINER,             /*!< 容器 */
    RGROUP,                 /*!< 分组 */
    RBUTTON,                /*!< 按钮 */
    RDYNAMIC_PANEL,         /*!< StackWidget */
    RDYNAMIC_PANEL_PAGE,    /*!< StackWidget页 */
    RTEXT_FIELD,            /*!< 单行文本框 */
    RRADIO_BUTTON,          /*!< 单选框 */
    RTABLE,                 /*!< 表格 */
    RTABLE_CELL,            /*!< 表格单元格 */
    RIMAGE,                 /*!< 图片 */
    RLABEL,                 /*!< 文本显示 */
    RLINE,                  /*!< 水平/竖直线条*/
    RLIST_BOX,              /*!< 列表框 */
    RTEXT_AREA,             /*!< 文本框 */
    RCHECKBOX,              /*!< 复选框 */
    RDROPLIST,              /*!< 下拉框 */
    RBOX,                   /*!< 矩形 */
    RINLINE_FRAME,          /*!< 内联窗口 */
    RTREE,                  /*!< 树形控件*/
    RSPINBOX,               /*!< 加减输入框*/
    RSCROLLBAR,             /*!< 滚动条*/
    RPROGRESSBAR,           /*!< 进度条*/
    RSLIDER,                /*!< 滑动条*/
    RTABWIDGET,             /*!< Tabwidget*/
    RTABWIDGET_PAGE,        /*!< Tab页 */
    RUNMENUBUTTON,          /*!< 菜单选项无触发按钮 */
    /***********识别自定义控件************/
    R_CUSTOM_TEXT_FIELD,                /*!< 自定义元件-输入框 */
    R_CUSTOM_VIRTUAL_CONTAINER          /*!< 自定义容器，此容器不会转换成Qt控件，但会携带信号槽等信息。 */
};

/*!
 * @brief head中link节点
 */
struct DomHead{
    QString m_title;
    QStringList m_links;
    QStringList m_scripts;
};

/*!
 * @brief 信号槽描述信息
 */
struct SignalSlotInfo{
    QString m_sender;
    QString m_signal;
    QString m_receiver;
    QString m_slot;
};

/*!
 * @brief 控件基础通用属性
 */
struct BaseData{
    BaseData():m_bChecked(false),m_bDisabled(false),m_bReadOnly(false),m_bLeftToRight(true),m_visible(true)
    ,m_left(0),m_top(0),m_width(0),m_height(0){}
    virtual ~BaseData(){}

    QString m_text;             /*!< 控件显示内容 */
    QString m_toolTip;          /*!< 工具提示信息，鼠标移入显示 */
    QString m_inlineStyle;      /*!< 内嵌的样式信息 */

    QString m_srcImage;         /*!< 正常状态背景图片*/
    QString m_srcImageId;       /*!< 正常状态背景图片控件id */
    QString m_checkedImage;     /*!< 选中状态图片 */
    QString m_unCheckedImage;   /*!< 未选中状态图片 */
    QString m_partiallyCheckedImage;   /*!< 半选中状态图片：主要用于checkox */

    QString m_specialTextId;    /*!< 自制控件文本 */
    QString m_widgetSizeId;     /*!< 自制控件大小id */
    QString m_textId;

    bool m_bChecked;            /*!< 是否默认选中：checkbox、radiobutton等需要选择的有效 */
    bool m_bDisabled;           /*!< 是否禁用 */
    bool m_bReadOnly;           /*!< 只读 */
    bool m_bLeftToRight;        /*!< 布局默认从左至右 */
    bool m_visible;             /*!< 是否可见：默认为可见，UI中即使不设置此属性也可以 */

    int m_left;
    int m_top;
    int m_width;
    int m_height;

    QStringList m_referenceIds;     /*!< 当前控件的样式需要引用其它ID的样式，可参考自定义控件‘输入框’中 */
    QString m_dataLabel;            /*!< 元素的data-label属性值 */

    QList<SignalSlotInfo> m_signals;      /*!< 需生成的信号槽描述信息 */
};

typedef QMap<QString,NodeType> CustControl;        //key：自定义控件名称，value：对应转换的自定义控件类型

/*!
 * @brief 图像数据
 */
struct ImageData : public BaseData{
    ~ImageData(){}

    QString m_src;          /*!< 图片链接:img节点特有 */
};

/*!
 * @brief 滚动条数据
 */
struct ScrollBarData : public BaseData{
    ~ScrollBarData(){}

    QString m_scrollBarId;          /*!< 滚动条 */
    QString m_scrollSlotId;         /*!< 滚动槽 */

    QString m_subLineId;            /*!< 下翻 */
    QString m_upArrowImage;

    QString m_addLineId;            /*!< 上翻 */
    QString m_downArrowImage;
};

/*!
 * @brief 滑动条
 */
struct SliderData : public BaseData{
    SliderData(){}
    ~SliderData(){}

    QString m_progressBarId;          /*!< 进度条 */
    QString m_progressSlotId;         /*!< 进度槽 */
    QString m_handleId;               /*!< 滑块默认状态Id */
    QString m_pressedHandleId;        /*!< 滑块按压状态Id */
};

/*!
 * @brief 动态面板数据
 */
struct PanelData : public BaseData{
    PanelData():m_currentIndex(0){}
    ~PanelData(){}

    QString m_panelDataLabel;           /*!< DynamicPanel中最外层data-label标签内容 */
    QString m_sonPanelStateId;          /*!< 二级动态面板id*/
    QString m_panelTextId;

    int m_currentIndex;                 /*!< 面板默认选中的索引，从0开始 */
};

struct CellData{
    QString id;
    QString imageSrc;
    QString text;
};

/*!
 * @brief 表格数据
 */
struct TableData : public BaseData{
    ~TableData(){}

    int m_rows;
    int m_colums;
    QList<CellData> m_cells;
    QString m_itemId;
};

struct TreeNodeData{
    bool valid(){return (!timestamp.isEmpty() && !simpleInfo.isEmpty() && !detailInfo.isEmpty());}
    QString timestamp;
    QString simpleInfo;     /*!< 简要信息 */
    QString detailInfo;     /*!< 详情信息 */
};

struct TreeData : public BaseData{
    TreeData(){}
    ~TreeData(){
    }

    QList<TreeNodeData> m_treeDatas;        /*!< 树形节点信息 */
};

/*!
 * @brief 分组数据
 */
struct GroupData : public BaseData{
    GroupData(){}
    ~GroupData(){}

    QString m_geometryReferenceId;      /*!< 自定义控件’触发弹窗‘中窗体的尺寸需要依赖子div中’框‘的尺寸 */
};

/*!
 * @brief SpinBox数据
 */
struct SpinboxData : public BaseData{
    SpinboxData(){}
    ~SpinboxData(){}

    QString m_spinBoxId;     /*!< 加减输入框id */
    QString m_sinBoxTextId;  /*!< 加减输入框的文字id */

    QString m_upArrowImage;     /*!< 上箭头默认状态 */
    QString m_downArrowImage;   /*!< 下箭头默认状态 */
    QString m_upArrowMouseOverImage;     /*!< 上箭头鼠标悬停状态 */
    QString m_downArrowMouseOverImage;   /*!< 下箭头鼠标悬停状态 */
};

/*!
 * @brief QPushButton数据
 */
struct ButtonData : public BaseData{
    ButtonData():m_needMouseOver(true),m_needMousePressed(true),m_needMouseChecked(true){}
    ~ButtonData(){}

    bool m_needMouseOver;       /*!< 是否开启MouseOver属性 */
    bool m_needMousePressed;    /*!< 是否开启MousePressd属性 */
    bool m_needMouseChecked;    /*!< 是否开启MouseChecked属性 */
};

/*!
 * @brief 单行文本编辑框
 */
struct TextFieldData : public BaseData{
    TextFieldData():m_maxLength(32767){}

    QString m_type;         /*!< 文本类型：password、text等 */
    QString m_placeHolders; /*!< 文本占位符，生成在js中，无法提取 */
    int m_maxLength;        /*!< 文本最大长度 */
};

/*!
 * @brief 单列表或下拉框列表
 */
struct ListData : public BaseData{
    ListData(){}

    QStringList m_itemList;     /*!< 选项集合 */
    QString m_selectedValue;    /*!< 默认选择项 */
    QString m_arrowImageSrc;    /*!< 下拉箭头的默认背景 */
    QString m_arrowImageOn;     /*!< 下拉箭头的打开背景 */
    QString m_backGroundId;     /*!< 自制下拉框背景id */
};

/*!
 * @brief tab页
 */
struct TabWidgetData : public BaseData{
    TabWidgetData():m_selectedPageIndex(0){}

    int m_selectedPageIndex;    /*!< 默认选中的页面选项 */

    QString m_tabNormalImage;   /*!< 默认tab项中背景图片 */
    QString m_tabSelectedImage; /*!< 选中tab项背景图片 */
    QString m_tabRightImage;    /*!< tab项的右边框图片 */

    QString m_tabBarId;         /*!< 根据tabBarId来获取tab样式*/
    QString m_paneId;           /*!< 根据paneId来获取pane样式*/
};

/*!
 * @brief 元素节点属性
 * @details 元素节点可存在样式属性、节点类型属性、子节点属性、父亲节点属性
 */
struct DomNode{
    DomNode(NodeType type):m_type(type),m_parent(nullptr),m_data(nullptr){}
    DomNode():DomNode(RINVALID){}

    ~DomNode(){
        m_parent = nullptr;

        foreach(DomNode * node,m_childs){
            delete node;
        }

        if(m_data)
            delete m_data;
    }

    NodeType m_type;        /*!< 元素类型 */

    QString m_id;           /*!< id属性 */
    QString m_class;        /*!< class属性 */
    QString m_style;        /*!< 控件中设置的样式属性 */

    QString m_treeText;

    BaseData * m_data;      /*!< 元素所具备的数据信息 */

    DomNode * m_parent;     /*!< 父节点,body节点parent为nullptr */
    QList<DomNode *> m_childs;     /*!< 子节点集合 */
};

/*!
 * @brief html文档节点结构
 * @details html文档解析后生成树形结构对象
 */
struct DomHtml{
    DomHead * head;         /*!< head节点 */
    DomNode * body;         /*!< body节点 */
};

} //namespace Html

typedef QSharedPointer<Html::DomHtml> DomHtmlPtr;

#endif // HTMLSTRUCT_H
