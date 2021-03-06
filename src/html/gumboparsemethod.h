﻿/*!
 *  @brief     使用gumbo库解析html，生成控件树
 *  @details   google的gumbo库可以很好的解决html解析问题，规避了通过xml方式解析失败的问题
 *  @author    wey
 *  @version   1.0
 *  @date      2020.03.03
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note   20200304:wey:提取每种控件可转换的属性
 */
#ifndef GUMBOPARSEMETHOD_H
#define GUMBOPARSEMETHOD_H

#include <QSharedPointer>
#include <gumbo.h>
#include "../util/fileutils.h"
#include "../head.h"
#include "htmlstruct.h"
#include "gumbonodewrapper.h"

namespace Html{

class GumboParseMethod : public RTextParseMethod
{
public:
    GumboParseMethod();
    ~GumboParseMethod();

    bool startParse(RTextFile * file) override;

    DomHtmlPtr getParsedResult(){return m_htmlResultPtr;}

private:
    void skipBomHead(RTextFile * file);
    bool parseFile(RTextFile * file);

    void parseBody(GumboNodeWrapper &bodyNode);
    void parseDiv(GumboNodeWrapper &divNode, DomNode *parentNode);

    NodeType getNodeType(GumboNodeWrapper &element, GumboNodeWrapper parentElement);

    void printBody(DomNode *node);
    inline void establishRelation(DomNode *parentNode,DomNode *childNode);

    //解析特定控件
    void parseNodeData(GumboNodeWrapper &element, NodeType type, DomNode *node);
    void parseContainerNodeData(GumboNodeWrapper &element, DomNode *node);
    void parseButtonNodeData(GumboNodeWrapper &element, DomNode *node);
    void parseRadioButtonNodeData(GumboNodeWrapper &element, DomNode *node);
    void parseDynamicPanelNodeData(GumboNodeWrapper &element, DomNode *node);
    void parseTextFieldNodeData(GumboNodeWrapper &element, DomNode *node);
    void parseImageNodeData(GumboNodeWrapper &element, DomNode *node);
    void parseTableNodeData(GumboNodeWrapper &element, DomNode *node);
    void parseTableCellNodeData(GumboNodeWrapper &element, DomNode *parentNode);
    void parseLineNodeData(GumboNodeWrapper &element, DomNode *node);
    void parseListNodeData(GumboNodeWrapper &element,DomNode *node);
    void parseTextAreaNodeData(GumboNodeWrapper &element,DomNode *node);
    void parseInlineFrameNodeData(GumboNodeWrapper &element,DomNode *node);
    void parseBoxNodeData(GumboNodeWrapper &element,DomNode *node);

    void parseTreeNodeData(GumboNodeWrapper &element, DomNode *node);

    void parseGroupNodeData(GumboNodeWrapper &element, DomNode *node);
    void parseLabelNodeData(GumboNodeWrapper &element, DomNode *node);    
    void parseSpinBoxNodeData(GumboNodeWrapper &element,DomNode *node);
    void parseScrollBarNodeData(GumboNodeWrapper &element,DomNode *node);
    void parseProgreesBarNodeData(GumboNodeWrapper &element,DomNode *node);
    void parseTabWidgetNodeData(GumboNodeWrapper &element,DomNode *node);

    void parseCustomInputEdit(GumboNodeWrapper &element,DomNode *node);
    void parseCustomVirtualContainer(GumboNodeWrapper &element,DomNode *node);

private:
    DomHtmlPtr m_htmlResultPtr;

    QString m_errorMsg;
    GumboOutput * m_gumboParser;
    QString m_classInfo;
    QString m_treeDatas;
    QStringList m_panlIdList;
    CustControl m_custControl;          //自定义输入框与可转换的控件类型
};

} //namespace Html

#endif // GUMBOPARSEMETHOD_H
