package com.guigod.cobagui;

import com.intellij.uiDesigner.core.GridConstraints;
import com.intellij.uiDesigner.core.GridLayoutManager;
import org.mariadb.jdbc.export.Prepare;

import javax.swing.*;
import javax.swing.border.TitledBorder;
import javax.swing.plaf.FontUIResource;
import javax.swing.table.DefaultTableModel;
import javax.swing.text.StyleContext;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;
import java.util.Locale;

public class Perpustakaan extends JFrame {
    private JPanel contentPane;
    private JTextField fieldKodeBuku;
    private JTextField fieldJudulBuku;
    private JTextField fieldPengarang;
    private JTextField fieldPenerbit;
    private JButton buttonTambah;
    private JButton buttonUbah;
    private JButton buttonHapus;
    private JTable tabelHasil;
    private JLabel labelKodeBuku;
    private JLabel labelJudulBuku;
    private JLabel labelPengarang;
    private JLabel labelPenerbit;
    private JPanel leftPanel;
    private JPanel rightPanel;
    private JScrollPane rightScrollPane;
    private JButton buttonCari;
    private JPanel panelButtons;

    private DefaultTableModel tableModel;
    private boolean editMode = false;
    private int editRow;

    public Perpustakaan() {
        // Set Look and Feel
//        try { UIManager.setLookAndFeel("com.sun.java.swing.plaf.gtk.GTKLookAndFeel");
//        } catch (Exception err) {
//            System.out.println("Error setting look and feel");
//        }

        // Initial Frame Setup
        setContentPane(contentPane);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(900, 600);

        // Table setup
        tableModel = new DefaultTableModel() {

            @Override
            public boolean isCellEditable(int row, int column) {
                return editMode && editRow == row && column != 0;
            }
        };

        tabelHasil.setModel(tableModel);

        tableModel.addColumn("Kode Buku");
        tableModel.addColumn("Judul Buku");
        tableModel.addColumn("Pengarang");
        tableModel.addColumn("Penerbit");

        loadTableData();

        buttonHapus.addActionListener(actionEvent -> {
            int[] selectedRows = tabelHasil.getSelectedRows();
            if (selectedRows.length == 0) {
                JOptionPane.showMessageDialog(this, "Please select a row to delete!", "Error", JOptionPane.WARNING_MESSAGE);
                return;
            }

            int confirmation = JOptionPane.showConfirmDialog(this, "Are you sure you want to delete this book(s)?", "Confirm Deletion", JOptionPane.YES_NO_OPTION);

            if (confirmation == JOptionPane.YES_OPTION) {
                for (int row : selectedRows) {
                    String kodeBuku = (String) tableModel.getValueAt(row, 0);
                    Connection db_connection = DBConnection.getConnection();
                    try {
                        String sql = "DELETE FROM buku WHERE kode_buku = ?;";
                        PreparedStatement stmt = db_connection.prepareStatement(sql);
                        stmt.setString(1, kodeBuku);
                        stmt.executeUpdate();
                        stmt.close();

                    } catch (SQLException err) {
                        System.out.println("Error Deleting Table Data");
                        System.out.println(err.getMessage());
                    }
                }
            }

            loadTableData();
        });

        buttonTambah.addActionListener(actionEvent -> {
            String inputKode = fieldKodeBuku.getText();
            String inputJudul = fieldJudulBuku.getText();
            String inputPengarang = fieldPengarang.getText();
            String inputPenerbit = fieldPenerbit.getText();

            if (inputKode.isEmpty() || inputJudul.isEmpty() || inputPengarang.isEmpty() || inputPenerbit.isEmpty()) {
                JOptionPane.showMessageDialog(this, "All fields are required!", "Validation Error", JOptionPane.WARNING_MESSAGE);
                return;
            }

            if (inputKode.length() > 5 || inputJudul.length() > 20 || inputPengarang.length() > 15 || inputPenerbit.length() > 15) {
                JOptionPane.showMessageDialog(this, "Fields exceed amount of characters!", "Validation Error", JOptionPane.WARNING_MESSAGE);
                return;
            }

            // Save to database
            Connection db_connection = DBConnection.getConnection();
            try {
                String sql = "INSERT INTO buku (kode_buku, judul_buku, pengarang, penerbit) VALUES (?, ?, ?, ?);";
                PreparedStatement stmt = db_connection.prepareStatement(sql);
                stmt.setString(1, inputKode);
                stmt.setString(2, inputJudul);
                stmt.setString(3, inputPengarang);
                stmt.setString(4, inputPenerbit);
                stmt.executeUpdate();
                stmt.close();


            } catch (SQLException err) {
                System.out.println("Error Inserting Table Data");
                System.out.println(err.getMessage());
            }

            loadTableData();
        });

        buttonCari.addActionListener(actionEvent -> {
            String inputKode = fieldKodeBuku.getText();
            String inputJudul = fieldJudulBuku.getText();
            String inputPengarang = fieldPengarang.getText();
            String inputPenerbit = fieldPenerbit.getText();
            Object[] queryArray = {inputKode, inputJudul, inputPengarang, inputPenerbit};

            if (inputKode.isEmpty() && inputJudul.isEmpty() && inputPengarang.isEmpty() && inputPenerbit.isEmpty()) {
                loadTableData();
                return;
            }

            if (inputKode.length() > 5 || inputJudul.length() > 20 || inputPengarang.length() > 15 || inputPenerbit.length() > 15) {
                JOptionPane.showMessageDialog(this, "Fields exceed amount of characters!", "Validation Error", JOptionPane.WARNING_MESSAGE);
                return;
            }

            // Search
            loadTableData(queryArray);
        });

        buttonUbah.addActionListener(actionEvent -> {
            if (tabelHasil.getSelectedRowCount() == 0) {
                JOptionPane.showMessageDialog(this, "Please select a row!", "Error", JOptionPane.WARNING_MESSAGE);
                return;
            }

            if (editMode) {
                buttonUbah.setText("Ubah");
                try {
                    String inputKode = tableModel.getValueAt(editRow, 0).toString();
                    String inputJudul = tableModel.getValueAt(editRow, 1).toString();
                    String inputPengarang = tableModel.getValueAt(editRow, 2).toString();
                    String inputPenerbit = tableModel.getValueAt(editRow, 3).toString();

                    Connection db_connection = DBConnection.getConnection();
                    String sql = "UPDATE buku SET judul_buku = ?, pengarang = ?, penerbit = ? WHERE kode_buku = ?;";
                    PreparedStatement stmt = db_connection.prepareStatement(sql);
                    stmt.setString(1, inputJudul);
                    stmt.setString(2, inputPengarang);
                    stmt.setString(3, inputPenerbit);
                    stmt.setString(4, inputKode);
                    stmt.executeUpdate();
                    stmt.close();

                } catch (SQLException err) {
                    System.out.println("error anjing");
                    System.out.println(err.getMessage());
                }
            } else {
                buttonUbah.setText("Apply");
                editRow = tabelHasil.getSelectedRow();
                tabelHasil.editCellAt(editRow, 1);
            }

            buttonCari.setEnabled(!buttonCari.isEnabled());
            buttonTambah.setEnabled(!buttonTambah.isEnabled());
            buttonHapus.setEnabled(!buttonHapus.isEnabled());
            fieldKodeBuku.setEnabled(!fieldKodeBuku.isEnabled());
            fieldJudulBuku.setEnabled(!fieldJudulBuku.isEnabled());
            fieldPengarang.setEnabled(!fieldPengarang.isEnabled());
            fieldPenerbit.setEnabled(!fieldPenerbit.isEnabled());
            editMode = !editMode;

        });

        setVisible(true);
    }



    private void loadTableData() {
        tableModel.getDataVector().removeAllElements();
        tableModel.fireTableDataChanged();

        Connection db_connection = DBConnection.getConnection();
        try {
            Statement stmt = db_connection.createStatement();
            String sql = "SELECT * from buku;";
            ResultSet rs = stmt.executeQuery(sql);

            while (rs.next()) {
                Object[] row = new Object[4];
                row[0] = rs.getString("kode_buku");
                row[1] = rs.getString("judul_buku");
                row[2] = rs.getString("pengarang");
                row[3] = rs.getString("penerbit");
                tableModel.addRow(row);
            }

            stmt.close();

        } catch (SQLException err) {
            System.out.println("Error Loading Table Data");
            System.out.println(err.getMessage());
        }
    }

    private void loadTableData(Object[] fields) {
        tableModel.getDataVector().removeAllElements();
        tableModel.fireTableDataChanged();

        Connection db_connection = DBConnection.getConnection();
        try {
            String sql = "SELECT * from buku WHERE kode_buku LIKE ? AND judul_buku LIKE ? AND pengarang LIKE ? AND penerbit LIKE ?;";
            PreparedStatement stmt = db_connection.prepareStatement(sql);
            stmt.setString(1, "%" + fields[0].toString() + "%");
            stmt.setString(2, "%" + fields[1].toString() + "%");
            stmt.setString(3, "%" + fields[2].toString() + "%");
            stmt.setString(4, "%" + fields[3].toString() + "%");
            ResultSet rs = stmt.executeQuery();

            while (rs.next()) {
                Object[] row = new Object[4];
                row[0] = rs.getString("kode_buku");
                row[1] = rs.getString("judul_buku");
                row[2] = rs.getString("pengarang");
                row[3] = rs.getString("penerbit");
                tableModel.addRow(row);
            }

            stmt.close();

        } catch (SQLException err) {
            System.out.println("Error Loading Table Data");
            System.out.println(err.getMessage());
        }
    }

    public static void main(String[] args) {
        new Perpustakaan();
    }

    {
// GUI initializer generated by IntelliJ IDEA GUI Designer
// >>> IMPORTANT!! <<<
// DO NOT EDIT OR ADD ANY CODE HERE!
        $$$setupUI$$$();
    }

    /**
     * Method generated by IntelliJ IDEA GUI Designer
     * >>> IMPORTANT!! <<<
     * DO NOT edit this method OR call it in your code!
     *
     * @noinspection ALL
     */
    private void $$$setupUI$$$() {
        contentPane = new JPanel();
        contentPane.setLayout(new GridLayoutManager(1, 2, new Insets(0, 0, 0, 0), -1, -1));
        leftPanel = new JPanel();
        leftPanel.setLayout(new GridLayoutManager(6, 2, new Insets(40, 20, 40, 10), -1, -1));
        contentPane.add(leftPanel, new GridConstraints(0, 0, 1, 1, GridConstraints.ANCHOR_EAST, GridConstraints.FILL_NONE, GridConstraints.SIZEPOLICY_FIXED, GridConstraints.SIZEPOLICY_FIXED, null, new Dimension(400, 500), null, 0, false));
        labelJudulBuku = new JLabel();
        labelJudulBuku.setText("Judul Buku");
        leftPanel.add(labelJudulBuku, new GridConstraints(2, 0, 1, 1, GridConstraints.ANCHOR_NORTHWEST, GridConstraints.FILL_NONE, GridConstraints.SIZEPOLICY_FIXED, GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        fieldJudulBuku = new JTextField();
        leftPanel.add(fieldJudulBuku, new GridConstraints(2, 1, 1, 1, GridConstraints.ANCHOR_NORTHWEST, GridConstraints.FILL_HORIZONTAL, GridConstraints.SIZEPOLICY_WANT_GROW, GridConstraints.SIZEPOLICY_FIXED, null, new Dimension(150, -1), null, 0, false));
        fieldPengarang = new JTextField();
        leftPanel.add(fieldPengarang, new GridConstraints(3, 1, 1, 1, GridConstraints.ANCHOR_NORTHWEST, GridConstraints.FILL_HORIZONTAL, GridConstraints.SIZEPOLICY_WANT_GROW, GridConstraints.SIZEPOLICY_FIXED, null, new Dimension(150, -1), null, 0, false));
        labelKodeBuku = new JLabel();
        labelKodeBuku.setText("Kode Buku");
        leftPanel.add(labelKodeBuku, new GridConstraints(1, 0, 1, 1, GridConstraints.ANCHOR_NORTHWEST, GridConstraints.FILL_NONE, GridConstraints.SIZEPOLICY_FIXED, GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        fieldKodeBuku = new JTextField();
        leftPanel.add(fieldKodeBuku, new GridConstraints(1, 1, 1, 1, GridConstraints.ANCHOR_NORTHWEST, GridConstraints.FILL_HORIZONTAL, GridConstraints.SIZEPOLICY_WANT_GROW, GridConstraints.SIZEPOLICY_FIXED, null, new Dimension(150, -1), null, 0, false));
        panelButtons = new JPanel();
        panelButtons.setLayout(new GridLayoutManager(1, 3, new Insets(0, 0, 0, 0), -1, -1));
        leftPanel.add(panelButtons, new GridConstraints(5, 0, 1, 2, GridConstraints.ANCHOR_CENTER, GridConstraints.FILL_BOTH, GridConstraints.SIZEPOLICY_CAN_SHRINK | GridConstraints.SIZEPOLICY_CAN_GROW, GridConstraints.SIZEPOLICY_CAN_SHRINK | GridConstraints.SIZEPOLICY_CAN_GROW, null, null, null, 0, true));
        buttonCari = new JButton();
        buttonCari.setText("Cari");
        panelButtons.add(buttonCari, new GridConstraints(0, 0, 1, 1, GridConstraints.ANCHOR_NORTH, GridConstraints.FILL_HORIZONTAL, GridConstraints.SIZEPOLICY_FIXED, GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        buttonTambah = new JButton();
        buttonTambah.setText("Tambah");
        panelButtons.add(buttonTambah, new GridConstraints(0, 1, 1, 1, GridConstraints.ANCHOR_NORTH, GridConstraints.FILL_HORIZONTAL, GridConstraints.SIZEPOLICY_FIXED, GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        fieldPenerbit = new JTextField();
        leftPanel.add(fieldPenerbit, new GridConstraints(4, 1, 1, 1, GridConstraints.ANCHOR_NORTHWEST, GridConstraints.FILL_HORIZONTAL, GridConstraints.SIZEPOLICY_WANT_GROW, GridConstraints.SIZEPOLICY_FIXED, null, new Dimension(150, -1), null, 0, false));
        labelPengarang = new JLabel();
        labelPengarang.setText("Pengarang");
        leftPanel.add(labelPengarang, new GridConstraints(3, 0, 1, 1, GridConstraints.ANCHOR_NORTHWEST, GridConstraints.FILL_NONE, GridConstraints.SIZEPOLICY_FIXED, GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        labelPenerbit = new JLabel();
        labelPenerbit.setText("Penerbit");
        leftPanel.add(labelPenerbit, new GridConstraints(4, 0, 1, 1, GridConstraints.ANCHOR_NORTHWEST, GridConstraints.FILL_NONE, GridConstraints.SIZEPOLICY_FIXED, GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        final JLabel label1 = new JLabel();
        Font label1Font = this.$$$getFont$$$(null, Font.BOLD, 24, label1.getFont());
        if (label1Font != null) label1.setFont(label1Font);
        label1.setText("Daftar Buku Perpustakaan");
        leftPanel.add(label1, new GridConstraints(0, 0, 1, 2, GridConstraints.ANCHOR_NORTH, GridConstraints.FILL_NONE, GridConstraints.SIZEPOLICY_FIXED, GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        rightPanel = new JPanel();
        rightPanel.setLayout(new GridLayoutManager(2, 1, new Insets(40, 10, 40, 20), -1, -1));
        contentPane.add(rightPanel, new GridConstraints(0, 1, 1, 1, GridConstraints.ANCHOR_WEST, GridConstraints.FILL_NONE, 1, GridConstraints.SIZEPOLICY_FIXED, new Dimension(400, 500), new Dimension(700, 500), new Dimension(700, 500), 0, false));
        rightScrollPane = new JScrollPane();
        rightPanel.add(rightScrollPane, new GridConstraints(0, 0, 1, 1, GridConstraints.ANCHOR_CENTER, GridConstraints.FILL_BOTH, GridConstraints.SIZEPOLICY_CAN_SHRINK | GridConstraints.SIZEPOLICY_WANT_GROW, GridConstraints.SIZEPOLICY_CAN_SHRINK | GridConstraints.SIZEPOLICY_WANT_GROW, null, null, null, 0, false));
        rightScrollPane.setBorder(BorderFactory.createTitledBorder(BorderFactory.createLineBorder(new Color(-16119286)), null, TitledBorder.DEFAULT_JUSTIFICATION, TitledBorder.DEFAULT_POSITION, null, null));
        tabelHasil = new JTable();
        tabelHasil.setAutoCreateRowSorter(false);
        rightScrollPane.setViewportView(tabelHasil);
        final JPanel panel1 = new JPanel();
        panel1.setLayout(new GridLayoutManager(1, 2, new Insets(20, 0, 0, 0), -1, -1));
        rightPanel.add(panel1, new GridConstraints(1, 0, 1, 1, GridConstraints.ANCHOR_CENTER, GridConstraints.FILL_BOTH, GridConstraints.SIZEPOLICY_CAN_SHRINK | GridConstraints.SIZEPOLICY_CAN_GROW, GridConstraints.SIZEPOLICY_CAN_SHRINK | GridConstraints.SIZEPOLICY_CAN_GROW, null, null, null, 0, false));
        buttonHapus = new JButton();
        buttonHapus.setText("Hapus");
        panel1.add(buttonHapus, new GridConstraints(0, 0, 1, 1, GridConstraints.ANCHOR_CENTER, GridConstraints.FILL_HORIZONTAL, GridConstraints.SIZEPOLICY_FIXED, GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        buttonUbah = new JButton();
        buttonUbah.setText("Ubah");
        panel1.add(buttonUbah, new GridConstraints(0, 1, 1, 1, GridConstraints.ANCHOR_NORTH, GridConstraints.FILL_HORIZONTAL, GridConstraints.SIZEPOLICY_FIXED, GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        labelJudulBuku.setLabelFor(fieldJudulBuku);
        labelKodeBuku.setLabelFor(fieldKodeBuku);
        labelPengarang.setLabelFor(fieldPengarang);
        labelPenerbit.setLabelFor(fieldPenerbit);
    }

    /**
     * @noinspection ALL
     */
    private Font $$$getFont$$$(String fontName, int style, int size, Font currentFont) {
        if (currentFont == null) return null;
        String resultName;
        if (fontName == null) {
            resultName = currentFont.getName();
        } else {
            Font testFont = new Font(fontName, Font.PLAIN, 10);
            if (testFont.canDisplay('a') && testFont.canDisplay('1')) {
                resultName = fontName;
            } else {
                resultName = currentFont.getName();
            }
        }
        Font font = new Font(resultName, style >= 0 ? style : currentFont.getStyle(), size >= 0 ? size : currentFont.getSize());
        boolean isMac = System.getProperty("os.name", "").toLowerCase(Locale.ENGLISH).startsWith("mac");
        Font fontWithFallback = isMac ? new Font(font.getFamily(), font.getStyle(), font.getSize()) : new StyleContext().getFont(font.getFamily(), font.getStyle(), font.getSize());
        return fontWithFallback instanceof FontUIResource ? fontWithFallback : new FontUIResource(fontWithFallback);
    }

    /**
     * @noinspection ALL
     */
    public JComponent $$$getRootComponent$$$() {
        return contentPane;
    }


}
