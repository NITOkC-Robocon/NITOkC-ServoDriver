# NITOkC-ServoDriver

## 概要
弊部独自のサーボドライバの回路データ、およびプログラムです<br>
(※デフォルトブランチ：main)

## 機能
- 2セルLiPoバッテリーからの給電
  - マイコンへの給電(電源切り離し機能付き)
  - サーボへの給電(レギュレータにより6Vに降圧)
- 中点指定機能
- 出力選択機能
- PWM幅可変機能
- 外部入力機能
  - 基板上のスライドスイッチによって切り替え可能

## 環境
|          |     |
|   :-:    | --- |
| OS       | Windows 10 Pro |
| プログラム | Arm Keil Studio |
| 基板作成 | KiCad 7.0 |
| 使用マイコン | NUCLEO-F303K8 |
| 使用言語    | C++ |
| その他   | 弊部独自ライブラリの導入が必須(Privateリポジトリのため、今後依存関係を解消予定) |

## 開発者
[Resenaga_Byakko (Shogo Miyazato)](https://github.com/ByakkoMatsumiya)

## 連絡先
基板またはコードに関するお問い合わせは、[Issues](https://github.com/NITOkC-Robocon/NITOC-Robocon_HP/issues)または下記連絡先へお願い致します。
- [Twitter | @Seyanaga (趣味用アカウント)](https://twitter.com/Seyanaga)
- [Twitter | @Myaaaazato (ロボコン用アカウント)](https://twitter.com/Myaaaazato)
